#include "MatcherTab.h"

MatcherTab::MatcherTab(QWidget *parent) :
	QWidget(parent){
	QGridLayout* layout = new QGridLayout(this);
	layout->addWidget(this->_maxDist, 0, 0, 1, 1);
}

void MatcherTab::loadParameters(const CondensationParameters &parameters){
	this->_maxDist->setValue(parameters.MAX_DIST);
}

