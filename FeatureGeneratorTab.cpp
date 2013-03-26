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
}

void FeatureGeneratorTab::loadParameters(const CondensationParameters &parameters){
	this->_maxCorners->setValue(parameters.maxCorners);
	this->_qualityLevel->setValue(parameters.qualityLevel);
	this->_minDistance->setValue(parameters.minDistance);
	this->_blockSize->setValue(parameters.blockSize);
	this->_k->setValue(parameters.k);
	this->_useHarrisDetector->setToggled(parameters.useHarrisDetector);
}
