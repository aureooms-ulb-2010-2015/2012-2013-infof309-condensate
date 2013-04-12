#include "MainWindow.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QFileDialog>

//===================================================

FrameProcessor* MainWindow::generateProcessor(){
	return new SynchronizedCondensation<CustomCondensationTemplateV4>();
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

		this->_frameProcessor = this->generateProcessor();
		this->_parameterControlWidget->loadParameters(this->getSynchronizedAlgorithm()->getActualParameters());

		QObject::connect(this->_parameterControlWidget, SIGNAL(save()), this, SLOT(save()));
		QObject::connect(this->_parameterControlWidget, SIGNAL(load()), this, SLOT(load()));

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

void MainWindow::keyPressEvent(QKeyEvent* event){

	if(event->key() == Qt::Key_F7){
		return this->toggleParameterControlWidget();
	}

	return BasicWindow::keyPressEvent(event);
}

MainWindow::~MainWindow(){}

SynchronizedCondensation<CustomCondensationTemplateV4> *MainWindow::getSynchronizedAlgorithm(){
	return (SynchronizedCondensation<CustomCondensationTemplateV4>*) this->_frameProcessor;
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



void MainWindow::save(){
	QString fileName = this->getXMLFilePathSave();
	if(!fileName.isEmpty()){
		loader.save(this->getSynchronizedAlgorithm()->getActualParameters(), fileName);
	}
}

void MainWindow::load(){
	QString fileName = this->getXMLFilePathOpen();
	if(!fileName.isEmpty()){
		CondensationParameters parameters = loader.load(fileName);
		this->_parameterControlWidget->loadParameters(parameters);
		this->getSynchronizedAlgorithm()->changeParameters(parameters);
	}
}


QString MainWindow::getXMLFilePathOpen(){
	QString filePath = QFileDialog::getOpenFileName(this, tr("XML File Name For Loading"),this->_lastVisitedFolderOpen,tr("XML (*.xml);;Others (*.*)"));
	for(int i = filePath.length(); i > 0; --i){
		if(filePath.at(i-1) == QChar('/')){
			this->_lastVisitedFolderOpen = filePath.left(i);
			break;
		}
	}
	return filePath;
}


QString MainWindow::getXMLFilePathSave(){
	QString filePath = QFileDialog::getSaveFileName(this, tr("XML File Name For Saving"),this->_lastVisitedFolderSave,tr("XML (*.xml);;Others (*.*)"));
	for(int i = filePath.length(); i > 0; --i){
		if(filePath.at(i-1) == QChar('/')){
			this->_lastVisitedFolderSave = filePath.left(i);
			break;
		}
	}
	return filePath;
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
	this->getSynchronizedAlgorithm()->matcherTypeIndexChanged(index);
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
