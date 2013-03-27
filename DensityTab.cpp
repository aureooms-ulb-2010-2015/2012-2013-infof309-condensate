#include "DensityTab.h"

DensityTab::DensityTab(QWidget *parent) :
	QWidget(parent){
	QGridLayout* layout = new QGridLayout(this);
	layout->addWidget(this->_spreadRange, 0, 0, 1, 1);

	QObject::connect(this->_spreadRange, SIGNAL(valueChanged(int)), this, SIGNAL(spreadRangeChanged(int)));
}

void DensityTab::loadParameters(const CondensationParameters &parameters){
	this->_spreadRange->setValue(parameters.spreadRange);
}
