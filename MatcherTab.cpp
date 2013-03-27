#include "MatcherTab.h"

MatcherTab::MatcherTab(QWidget *parent) :
	QWidget(parent){
	QGridLayout* layout = new QGridLayout(this);
	layout->addWidget(this->_maxDist, 0, 0, 1, 1);
	layout->addWidget(this->_radius, 1, 0, 1, 1);


	QObject::connect(this->_maxDist, SIGNAL(valueChanged(int)), this, SIGNAL(maxDistChanged(int)));
	QObject::connect(this->_radius, SIGNAL(valueChanged(int)), this, SIGNAL(radiusChanged(int)));
}

void MatcherTab::loadParameters(const CondensationParameters &parameters){
	this->_maxDist->setValue(parameters.MAX_DIST);
	this->_radius->setValue(parameters.R);
}

