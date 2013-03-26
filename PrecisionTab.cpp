#include "PrecisionTab.h"

PrecisionTab::PrecisionTab(QWidget *parent) :
	QWidget(parent){
	QGridLayout* layout = new QGridLayout(this);
	layout->addWidget(this->_pollingRange, 0, 0, 1, 1);
	layout->addWidget(this->_generatingRange, 1, 0, 1, 1);
}

void PrecisionTab::loadParameters(const CondensationParameters &parameters){
	this->_pollingRange->setValue(parameters.pollingRange);
	this->_generatingRange->setValue(parameters.generatingRange);
}
