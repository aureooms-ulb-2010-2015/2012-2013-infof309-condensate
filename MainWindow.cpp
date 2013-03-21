#include "MainWindow.h"

#include <QApplication>
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

FrameProcessor* MainWindow::generateProcessor(){
	switch(this->_frameProcessorId){
    case 0:
		return new NoProcessing();
	case 1:
		return new BinaryMaskWithOriginalFrame(cv::Size(1,1));
	case 2:
		return new Tagging(0,0.01,cv::Size(1,1));
	case 3:
		return new Watershed(0, cv::Size(1,1));
	case 4:
		return new FeatureTracker();
	case 5:
		return new TagNTrack(cv::Size(1,1));
	case 6:
		return new OomsChallenge();
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
	this->_processingChoice->addItem("Binary Mask");
	this->_processingChoice->addItem("Tagging");
	this->_processingChoice->addItem("Watershed");
    this->_processingChoice->addItem("FeatureTracker");
	this->_processingChoice->addItem("TagNTrack");
	this->_processingChoice->addItem("ConDensAtion");
	this->_processingChoice->addItem("CustomCondensationV1");
	this->_processingChoice->addItem("CustomCondensationTemplateV2 (GreyLevelDistanceMatcher)");
    //...
}

//===================================================
//Ne pas toucher plus bas si c'est pour rajouter un algo.

MainWindow::MainWindow(QWidget *parent) : BasicWindow(parent){
	this->setWindowTitle("ConDensAte");

	this->initProcessingChoices();

	QHBoxLayout* upperBarLayout = new QHBoxLayout(this->_upperBar);
	upperBarLayout->addWidget(this->_inputChoice);
	upperBarLayout->addWidget(this->_processingChoice);
	upperBarLayout->setContentsMargins(0,0,0,0);

	QObject::connect(this->_processingChoice, SIGNAL(currentIndexChanged(int)), this, SLOT(changeFrameProcessorSLOT(int)));
}

MainWindow::~MainWindow(){}

void MainWindow::keyPressEvent(QKeyEvent* event){
	for(int i = 0; i < this->_processingChoice->count(); ++i){
		if( (QApplication::keyboardModifiers() & ~Qt::ShiftModifier ) == Qt::ControlModifier && event->key() == (Qt::Key_0 + i)){
			return this->_processingChoice->setCurrentIndex(i);
		}
	}
	return BasicWindow::keyPressEvent(event);
}

void MainWindow::changeFrameProcessorSLOT(int index){
	this->_frameProcessorId = index;
	bool wasPlaying = this->_videoControls->isPlaying();
	if(wasPlaying){
		this->_displayer->pause();
	}
	this->_streamProcessor->stop();
	delete this->_frameProcessor;
	this->_frameProcessor = this->generateProcessor();
	this->_streamProcessor->reset(this->_streamReader, this->_frameProcessor);
	if(wasPlaying){
		this->_displayer->play();
		this->_videoControls->setPlaying();
	}
}
