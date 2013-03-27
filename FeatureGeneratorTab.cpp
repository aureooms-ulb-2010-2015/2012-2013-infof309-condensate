#include "FeatureGeneratorTab.h"

FeatureGeneratorTab::FeatureGeneratorTab(QWidget *parent) :
	QWidget(parent){
	QGridLayout* layout = new QGridLayout(this);
	layout->addWidget(this->_maxCorners, 0, 0, 1, 1);
	layout->addWidget(this->_qualityLevel, 1, 0, 1, 1);
	layout->addWidget(this->_minDistance, 2, 0, 1, 1);
	layout->addWidget(this->_blockSize, 3, 0, 1, 1);
	layout->addWidget(this->_k, 4, 0, 1, 1);
	layout->addWidget(this->_useHarrisDetector, 5, 0, 1, 1);


	QObject::connect(this->_maxCorners, SIGNAL(valueChanged(int)), this, SIGNAL(maxCornersChanged(int)));
	QObject::connect(this->_qualityLevel, SIGNAL(valueChanged(int)), this, SLOT(qualityLevelChangedSLOT(int)));
	QObject::connect(this->_minDistance, SIGNAL(valueChanged(int)), this, SIGNAL(minDistanceChanged(int)));
	QObject::connect(this->_blockSize, SIGNAL(valueChanged(int)), this, SIGNAL(blockSizeChanged(int)));
	QObject::connect(this->_k, SIGNAL(valueChanged(int)), this, SLOT(kChangedSLOT(int)));
	QObject::connect(this->_useHarrisDetector, SIGNAL(toggled(bool)), this, SIGNAL(useHarrisDetectorChanged(bool)));
}

void FeatureGeneratorTab::loadParameters(const CondensationParameters &parameters){
	this->_maxCorners->setValue(parameters.maxCorners);
	this->_qualityLevel->setValue(parameters.qualityLevel*PRECISION);
	this->_minDistance->setValue(parameters.minDistance);
	this->_blockSize->setValue(parameters.blockSize);
	this->_k->setValue(parameters.k*PRECISION);
	this->_useHarrisDetector->setToggled(parameters.useHarrisDetector);
}

void FeatureGeneratorTab::qualityLevelChangedSLOT(int value){
	emit qualityLevelChanged(value/PRECISION);
}

void FeatureGeneratorTab::kChangedSLOT(int value){
	emit kChanged(value/PRECISION);
}
