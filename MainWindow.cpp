#include "MainWindow.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QDesktopWidget>
#include "ImageDisplayerWidgetImpl.h"
#include "ImageDisplayerWidgetImpl2.h"
#include "ImageDisplayerWidgetImpl3.h"
#include "Algorithm_NoProcessing.h"
#include "Algorithm_Tagging.h"
#include "Algorithm_FeaturesTracker.h"
#include "Algorithm_TagAnTrack.h"
#include "Algorithm_BinaryMaskWithOriginalFrame.h"
#include "Algorithm_Watershed.h"
#include "Algorithm_OomsChallenge.h"
#include "Algorithm_CustomCondensationV1.h"
#include "Algorithm_CustomCondensationTemplateV2.h"
#include "Matcher_GreyLevelDistanceMatcher.h"

//===================================================
// Le seul code auquel il faut toucher pour rajouter des algos à pouvoir exécuter, attention à respecter l'ordre!!

FrameProcessor* MainWindow::generateProcessor(int index){
    switch(index){
    case 0:
		return new NoProcessing();
    case 1:
		return new Tagging(0,0.01,cv::Size(1,1));
	case 2:
		return new FeatureTracker();
	case 3:
		return new TagNTrack();
	case 4:
		return new Watershed();
	case 5:
		return new OomsChallenge();
	case 6:
		return new BinaryMaskWithOriginalFrame(cv::Size(1,1));
	case 7:
		return new CustomCondensationV1();
	case 8:
		return new CustomCondensationTemplateV2<GreyLevelDistanceMatcher<6> >();
        //...

    }

    return NULL;
}


void MainWindow::initProcessingChoices(){
    this->_processingChoice->addItem("Pas de traitement");
	this->_processingChoice->addItem("Tagging");
    this->_processingChoice->addItem("FeatureTracker");
	this->_processingChoice->addItem("TagNTrack");
	this->_processingChoice->addItem("Watershed");
	this->_processingChoice->addItem("Condensation");
	this->_processingChoice->addItem("Binary Mask");
	this->_processingChoice->addItem("CustomCondensationV1");
	this->_processingChoice->addItem("CustomCondensationTemplateV2 (GreyLevelDistanceMatcher)");
    //...
}

//===================================================
//Ne pas toucher plus bas si c'est pour rajouter un algo.



void MainWindow::centerWindow(){
	this->show();
	QRect r(this->frameGeometry());
	r.moveCenter(QApplication::desktop()->availableGeometry().center());
	this->move(r.topLeft());
}


MainWindow::MainWindow(QWidget *parent) :
	QWidget(parent),_frameProcessorId(0){

	this->setWindowTitle("ConDensAte");

	this->_wraper = new QWidget(this);
	this->_wraper->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);


	//--------------------------------------------------------------------
	this->_inputChoice = new InputChoiceWidget();
	this->_processingChoice = new ProcessingChoiceWidget();
	this->initProcessingChoices();
	this->_upperBar = new QWidget();
	QHBoxLayout* upperBarLayout = new QHBoxLayout(this->_upperBar);
	upperBarLayout->addWidget(this->_inputChoice);
	upperBarLayout->addWidget(this->_processingChoice);
	this->_upperBar->setFixedWidth(640);
	this->_upperBar->setFixedHeight(30);
	upperBarLayout->setContentsMargins(0,0,0,0);
	//--------------------------------------------------------------------
	this->_videoFrame = new ImageDisplayerWidgetImpl();
	//--------------------------------------------------------------------
	this->_videoControls = new VideoPlayControlsWidget();
	this->_videoControls->setFixedWidth(640);
	//--------------------------------------------------------------------

	this->_layout = new QGridLayout(this->_wraper);
	this->_layout->addWidget(this->_upperBar,0,0,1,1);
	this->_layout->addWidget(this->_videoFrame,1,0,1,1);
	this->_layout->addWidget(this->_videoControls,2,0,1,1);

	//--------------------------------------------------------------------

	//=================

	this->_streamReader = new VideoStreamReader();
	this->_frameProcessor = NULL;
	this->_streamProcessor = new VideoStreamProcessor(this->_streamReader,this->_frameProcessor);
	this->_displayer = new StreamDisplayer(this->_streamProcessor);


	QObject::connect(this->_inputChoice, SIGNAL(currentSourceChanged(int)), this, SLOT(requestChangeSourceSLOT(int)));
	QObject::connect(this->_inputChoice, SIGNAL(currentSourceChanged(QString)), this, SLOT(requestChangeSourceSLOT(QString)));

	QObject::connect(this->_displayer, SIGNAL(displaySIGNAL(QImage)), this->_videoFrame, SLOT(displayImageSLOT(QImage)));
	QObject::connect(this->_displayer, SIGNAL(posSIGNAL(int)), this, SLOT(posChangedSLOT(int)));


	QObject::connect(this->_videoControls, SIGNAL(pause()), this->_displayer, SLOT(pause()));
	QObject::connect(this->_videoControls, SIGNAL(play()), this->_displayer, SLOT(play()));
	QObject::connect(this->_videoControls, SIGNAL(timeChanged(int)), this, SLOT(timeChangedSLOT(int)));

	QObject::connect(this->_processingChoice, SIGNAL(currentIndexChanged(int)), this, SLOT(changeFrameProcessorSLOT(int)));

	this->setLayout(this->_layout);
	this->_streamProcessor->start();
	this->_displayer->start();


	this->centerWindow();
}

MainWindow::~MainWindow(){
	delete this->_streamReader;
	delete this->_streamProcessor;
	delete this->_frameProcessor;
	delete this->_displayer;
}

void MainWindow::keyPressEvent(QKeyEvent* event){

	if(event->key() == Qt::Key_F11){
		if (!this->isFullScreen()){
			return this->requestEnterFullScreenSLOT();
		}
		else{
			return this->requestExitFullScreenSLOT();
		}
	}
	else if(event->key() == Qt::Key_F4 && QApplication::keyboardModifiers() == Qt::AltModifier){
		return QCoreApplication::quit();
	}

	else if(event->key() == Qt::Key_F5){
		return reloadStream();
	}

	else if(event->key() == Qt::Key_F1){
		return this->playPauseToggle();
	}

	return QWidget::keyPressEvent(event);
}

void MainWindow::requestChangeSourceSLOT(int device){
	lastDevice = device;
	whichLast = 0;
	this->_displayer->pause();
	this->_streamProcessor->stop();
	this->_streamReader->open(device);
	this->sourceReady();
}

void MainWindow::requestChangeSourceSLOT(QString filename){
	lastPath = filename;
	whichLast = 1;
	this->_displayer->pause();
	this->_streamProcessor->stop();
	this->_streamReader->open(filename);
	this->sourceReady();
}

void MainWindow::sourceReady(){
	delete this->_frameProcessor;
	this->_frameProcessor = this->generateProcessor(this->_frameProcessorId);
	this->_streamProcessor->reset(this->_streamReader, this->_frameProcessor);
	this->_streamInfo = this->_streamReader->getSourceInfo();
	int totalTime = 0, elapsedTime = 0;
    this->_displayer->setFrameLength((this->_streamInfo.getFps() <= 0)? 40 : 1000/this->_streamInfo.getFps());

	if(this->_streamInfo.isOpen()){
		if(this->_streamInfo.getFps() > 0 && this->_streamInfo.getNumberOfFrames() > 0 && this->_streamInfo.getActualFrameNumber() >= 0){
			totalTime = this->_streamInfo.getNumberOfFrames()/this->_streamInfo.getFps();
			elapsedTime = this->_streamInfo.getActualFrameNumber()/this->_streamInfo.getFps();
		}
	}
	this->_videoControls->setTotalTime(totalTime);
	this->_videoControls->setElapsedTime(elapsedTime);
	this->_videoFrame->reset();
	this->_videoFrame->setDimensions(this->_streamInfo.getFrameHeight(), this->_streamInfo.getFrameWidth());
	this->_displayer->play();
	this->_videoControls->setPlaying();
}



void MainWindow::reloadStream(){
	if(whichLast == -1) return;
	if(whichLast == 0){
		this->requestChangeSourceSLOT(lastDevice);
	}
	else{
		this->requestChangeSourceSLOT(lastPath);
	}
}

void MainWindow::playPauseToggle(){
	bool wasPlaying = this->_videoControls->isPlaying();
	if(wasPlaying){
		this->_displayer->pause();
		this->_videoControls->setPaused();
	}
	else{
		this->_displayer->play();
		this->_videoControls->setPlaying();
	}
}


void MainWindow::posChangedSLOT(int pos){
	int elapsedTime = 0;
	if(this->_streamInfo.getFps() > 0 && this->_streamInfo.getNumberOfFrames() > 0 && pos >= 0){
		elapsedTime = pos/this->_streamInfo.getFps();
	}
	this->_videoControls->setElapsedTime(elapsedTime);
	if(pos == this->_streamInfo.getNumberOfFrames() - 1){
		reloadStream();
	}
}

void MainWindow::timeChangedSLOT(int time){
	this->_streamProcessor->jumpTo(time*this->_streamInfo.getFps());
}

void MainWindow::changeFrameProcessorSLOT(int index){
    this->_frameProcessorId = index;
    bool wasPlaying = this->_videoControls->isPlaying();
    if(wasPlaying){
        this->_displayer->pause();
    }
	this->_streamProcessor->stop();
	delete this->_frameProcessor;
	this->_frameProcessor = this->generateProcessor(index);
    this->_streamProcessor->reset(this->_streamReader, this->_frameProcessor);
    if(wasPlaying){
        this->_displayer->play();
        this->_videoControls->setPlaying();
    }
}

void MainWindow::requestEnterFullScreenSLOT(){
    bool wasPlaying = this->_videoControls->isPlaying();
    if(wasPlaying){
        this->_displayer->pause();
    }
	this->_streamProcessor->stop();
	this->_videoFrame->reset();

	this->_upperBar->hide();
	this->_videoControls->hide();
	this->showFullScreen();
	this->_videoFrame->setMinimumSize(0,0);
	this->_videoFrame->setMaximumSize(QWIDGETSIZE_MAX,QWIDGETSIZE_MAX);
	this->_layout->setContentsMargins(0,0,0,0);

    this->_streamProcessor->reset(this->_streamReader, this->_frameProcessor);
    if(wasPlaying){
        this->_displayer->play();
        this->_videoControls->setPlaying();
    }
}

void MainWindow::requestExitFullScreenSLOT(){
    bool wasPlaying = this->_videoControls->isPlaying();
    if(wasPlaying){
        this->_displayer->pause();
    }
	this->_streamProcessor->stop();
	this->_videoFrame->reset();

	this->showNormal();
	this->_upperBar->show();
	this->_videoControls->show();
	this->_videoFrame->setFixedSize(640,480);
	this->_layout->setContentsMargins(10,10,10,10);

    this->_streamProcessor->reset(this->_streamReader, this->_frameProcessor);
    if(wasPlaying){
        this->_displayer->play();
        this->_videoControls->setPlaying();
    }
}