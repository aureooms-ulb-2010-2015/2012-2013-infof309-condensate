#include "MainWindow.h"

#include <QApplication>
#include <QDesktopWidget>

//===================================================

FrameProcessor* MainWindow::generateProcessor(){
	this->_frameProcessor = new SynchronizedCondensation<CustomCondensationTemplateV3>();
	this->_parameterControlWidget->loadParameters(this->getSynchronizedAlgorithm()->getActualParameters());
	return this->_frameProcessor;
}

MainWindow::MainWindow(QWidget *parent) : BasicWindow(parent){
        this->setWindowTitle("ConDensAte");

        QGridLayout* upperBarLayout = new QGridLayout(this->_upperBar);
        upperBarLayout->addWidget(this->_inputChoice, 0, 0, 1, 3);
        upperBarLayout->addWidget(this->_parameterToggle, 0, 3, 1, 1);
        this->_parameterToggle->setFixedHeight(23);
        this->_parameterToggle->setIcon(QIcon(":parameter_icon"));
        upperBarLayout->setContentsMargins(0,0,0,0);

		QObject::connect(this->_parameterToggle, SIGNAL(clicked()), this, SLOT(toggleParameterControlWidget()));

		this->generateProcessor();

		QObject::connect(this->_parameterControlWidget, SIGNAL(spreadRangeChanged(int)), this, SLOT(spreadRangeChangedSLOT(int)));
		QObject::connect(this->_parameterControlWidget, SIGNAL(resamplingPassesChanged(int)), this, SLOT(resamplingPassesChangedSLOT(int)));
		QObject::connect(this->_parameterControlWidget, SIGNAL(resamplingRangeChanged(int)), this, SLOT(resamplingRangeChangedSLOT(int)));
		QObject::connect(this->_parameterControlWidget, SIGNAL(maxCornersChanged(int)), this, SLOT(maxCornersChangedSLOT(int)));
		QObject::connect(this->_parameterControlWidget, SIGNAL(qualityLevelChanged(float)), this, SLOT(qualityLevelChangedSLOT(float)));
		QObject::connect(this->_parameterControlWidget, SIGNAL(minDistanceChanged(int)), this, SLOT(minDistanceChangedSLOT(int)));
		QObject::connect(this->_parameterControlWidget, SIGNAL(blockSizeChanged(int)), this, SLOT(blockSizeChangedSLOT(int)));
		QObject::connect(this->_parameterControlWidget, SIGNAL(kChanged(float)), this, SLOT(kChangedSLOT(float)));
		QObject::connect(this->_parameterControlWidget, SIGNAL(useHarrisDetectorChanged(bool)), this, SLOT(useHarrisDetectorChangedSLOT(bool)));
		QObject::connect(this->_parameterControlWidget, SIGNAL(matcherTypeChanged(int)), this, SLOT(matcherTypeChangedSLOT(int)));
		QObject::connect(this->_parameterControlWidget, SIGNAL(maxDistChanged(int)), this, SLOT(maxDistChangedSLOT(int)));
		QObject::connect(this->_parameterControlWidget, SIGNAL(radiusChanged(int)), this, SLOT(radiusChangedSLOT(int)));
		QObject::connect(this->_parameterControlWidget, SIGNAL(pollingRangeChanged(int)), this, SLOT(pollingRangeChangedSLOT(int)));
		QObject::connect(this->_parameterControlWidget, SIGNAL(generatingRangeChanged(int)), this, SLOT(generatingRangeChangedSLOT(int)));
		QObject::connect(this->_parameterControlWidget, SIGNAL(minWidthChanged(int)), this, SLOT(minWidthChangedSLOT(int)));
		QObject::connect(this->_parameterControlWidget, SIGNAL(maxWidthChanged(int)), this, SLOT(maxWidthChangedSLOT(int)));
		QObject::connect(this->_parameterControlWidget, SIGNAL(minHeightChanged(int)), this, SLOT(minHeightChangedSLOT(int)));
		QObject::connect(this->_parameterControlWidget, SIGNAL(maxHeightChanged(int)), this, SLOT(maxHeightChangedSLOT(int)));
		QObject::connect(this->_parameterControlWidget, SIGNAL(minAccumulatorIterationsChanged(int)), this, SLOT(minAccumulatorIterationsChangedSLOT(int)));
		QObject::connect(this->_parameterControlWidget, SIGNAL(startChanged(int)), this, SLOT(startChangedSLOT(int)));
		QObject::connect(this->_parameterControlWidget, SIGNAL(dieChanged(int)), this, SLOT(dieChangedSLOT(int)));
		QObject::connect(this->_parameterControlWidget, SIGNAL(bonusFactorChanged(int)), this, SLOT(bonusFactorChangedSLOT(int)));
		QObject::connect(this->_parameterControlWidget, SIGNAL(malusChanged(int)), this, SLOT(malusChangedSLOT(int)));
		QObject::connect(this->_parameterControlWidget, SIGNAL(minFeaturesChanged(int)), this, SLOT(minFeaturesChangedSLOT(int)));
}

MainWindow::~MainWindow(){}

SynchronizedCondensation<CustomCondensationTemplateV3> *MainWindow::getSynchronizedAlgorithm(){
	return (SynchronizedCondensation<CustomCondensationTemplateV3>*) this->_frameProcessor;
}

void MainWindow::toggleParameterControlWidget(){
        if(this->_parameterControlWidget->isVisible()){
			this->_parameterControlWidget->hide();
			if(!this->isFullScreen()){
				this->centerWindow();
			}
        }
        else{
			this->_parameterControlWidget->show();
			if(!this->isFullScreen()){
				this->splitScreen();
			}
		}
}

void MainWindow::splitScreen(){
	this->show();
	QRect leftRect(this->frameGeometry()), rightRect(this->_parameterControlWidget->frameGeometry());
	QPoint leftCenter, rightCenter, screenCenter;
	screenCenter = QApplication::desktop()->availableGeometry().center();
	leftCenter.setX(screenCenter.x()/2);
	leftCenter.setY(screenCenter.y());
	rightCenter.setX(screenCenter.x()*3/2);
	rightCenter.setY(screenCenter.y());
	leftRect.moveCenter(leftCenter);
	rightRect.moveCenter(rightCenter);
	this->_parameterControlWidget->move(rightRect.topLeft());
	this->move(leftRect.topLeft());
}




void MainWindow::spreadRangeChangedSLOT(int value){
	this->getSynchronizedAlgorithm()->spreadRangeChanged(value);
}

void MainWindow::maxCornersChangedSLOT(int value){
	this->getSynchronizedAlgorithm()->maxCornersChanged(value);
}

void MainWindow::qualityLevelChangedSLOT(float value){
	this->getSynchronizedAlgorithm()->qualityLevelChanged(value);
}

void MainWindow::minDistanceChangedSLOT(int value){
	this->getSynchronizedAlgorithm()->minDistanceChanged(value);
}

void MainWindow::blockSizeChangedSLOT(int value){
	this->getSynchronizedAlgorithm()->blockSizeChanged(value);
}

void MainWindow::kChangedSLOT(float value){
	this->getSynchronizedAlgorithm()->kChanged(value);
}

void MainWindow::useHarrisDetectorChangedSLOT(bool value){
	this->getSynchronizedAlgorithm()->useHarrisDetectorChanged(value);
}

void MainWindow::maxDistChangedSLOT(int value){
	this->getSynchronizedAlgorithm()->maxDistChanged(value);
}

void MainWindow::radiusChangedSLOT(int value){
	this->getSynchronizedAlgorithm()->radiusChanged(value);
}

void MainWindow::pollingRangeChangedSLOT(int value){
	this->getSynchronizedAlgorithm()->pollingRangeChanged(value);
}

void MainWindow::generatingRangeChangedSLOT(int value){
	this->getSynchronizedAlgorithm()->generatingRangeChanged(value);
}

void MainWindow::minWidthChangedSLOT(int value){
	this->getSynchronizedAlgorithm()->minWidthChanged(value);
}

void MainWindow::maxWidthChangedSLOT(int value){
	this->getSynchronizedAlgorithm()->maxWidthChanged(value);
}

void MainWindow::minHeightChangedSLOT(int value){
	this->getSynchronizedAlgorithm()->minHeightChanged(value);
}

void MainWindow::maxHeightChangedSLOT(int value){
	this->getSynchronizedAlgorithm()->maxHeightChanged(value);
}

void MainWindow::minAccumulatorIterationsChangedSLOT(int value){
	this->getSynchronizedAlgorithm()->minAccumulatorIterationsChanged(value);
}

void MainWindow::matcherTypeChangedSLOT(int index){
	if(index == 0){
		this->getSynchronizedAlgorithm()->matcherTypeChanged(std::shared_ptr<DistanceMatcher>(new GreyLevelDistanceMatcher(1)));
	}
	else if(index == 1){
		this->getSynchronizedAlgorithm()->matcherTypeChanged(std::shared_ptr<DistanceMatcher>(new GradientDistanceMatcher(1)));
	}
}

void MainWindow::startChangedSLOT(int value){
	this->getSynchronizedAlgorithm()->startChanged(value);
}

void MainWindow::dieChangedSLOT(int value){
	this->getSynchronizedAlgorithm()->dieChanged(value);
}

void MainWindow::bonusFactorChangedSLOT(int value){
	this->getSynchronizedAlgorithm()->bonusFactorChanged(value);
}

void MainWindow::malusChangedSLOT(int value){
	this->getSynchronizedAlgorithm()->malusChanged(value);
}

void MainWindow::minFeaturesChangedSLOT(int value){
	this->getSynchronizedAlgorithm()->minFeaturesChanged(value);
}

void MainWindow::resamplingPassesChangedSLOT(int value){
	this->getSynchronizedAlgorithm()->resamplingPassesChanged(value);
}

void MainWindow::resamplingRangeChangedSLOT(int value){
	this->getSynchronizedAlgorithm()->resamplingRangeChanged(value);
}
