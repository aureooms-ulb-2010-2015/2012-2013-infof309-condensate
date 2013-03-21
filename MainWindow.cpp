#include "MainWindow.h"

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

MainWindow::MainWindow(QWidget *parent) : BasicWindow(parent){
	this->setWindowTitle("FishTube");

	this->initProcessingChoices();

	QHBoxLayout* upperBarLayout = new QHBoxLayout(this->_upperBar);
	upperBarLayout->addWidget(this->_inputChoice);
	upperBarLayout->addWidget(this->_processingChoice);
	upperBarLayout->setContentsMargins(0,0,0,0);

	QObject::connect(this->_processingChoice, SIGNAL(currentIndexChanged(int)), this, SLOT(changeFrameProcessorSLOT(int)));
}

MainWindow::~MainWindow(){}

void MainWindow::keyPressEvent(QKeyEvent* event){
	//TODO ADD SHORTCUTS TO PROCESS
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
