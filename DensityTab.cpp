#include "DensityTab.h"

DensityTab::DensityTab(QWidget *parent) :
	QWidget(parent){
	QGridLayout* layout = new QGridLayout(this);
	layout->addWidget(this->_spreadRange, 0, 0, 1, 1);
	layout->addWidget(this->_resamplingPasses, 1, 0, 1, 1);
	layout->addWidget(this->_resamplingRange, 2, 0, 1, 1);

	QObject::connect(this->_spreadRange, SIGNAL(valueChanged(int)), this, SIGNAL(spreadRangeChanged(int)));
	QObject::connect(this->_resamplingPasses, SIGNAL(valueChanged(int)), this, SIGNAL(resamplingPassesChanged(int)));
	QObject::connect(this->_resamplingRange, SIGNAL(valueChanged(int)), this, SIGNAL(resamplingRangeChanged(int)));
}

void DensityTab::loadParameters(const CondensationParameters &parameters){
	this->_spreadRange->setValue(parameters.spreadRange);
	this->_resamplingPasses->setValue(parameters.resamplingPasses);
	this->_resamplingRange->setValue(parameters.resamplingRange);
}
