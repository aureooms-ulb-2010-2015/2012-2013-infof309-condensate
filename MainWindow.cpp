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

FrameProcessor* MainWindow::generateProcessor(){
	return new CustomCondensationTemplateV2<GreyLevelDistanceMatcher<6> >();
}

MainWindow::MainWindow(QWidget *parent) : BasicWindow(parent){
	this->setWindowTitle("ConDensAte");

	QHBoxLayout* upperBarLayout = new QHBoxLayout(this->_upperBar);
	upperBarLayout->addWidget(this->_inputChoice);
	upperBarLayout->addWidget(this->_parameterToggle);
	this->_parameterToggle->setFixedHeight(23);
	upperBarLayout->setContentsMargins(0,0,0,0);
}

MainWindow::~MainWindow(){}
