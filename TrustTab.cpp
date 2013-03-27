#include "TrustTab.h"
#include <QGridLayout>

TrustTab::TrustTab(QWidget *parent) :
	QWidget(parent){
	QGridLayout* layout = new QGridLayout(this);
	layout->addWidget(this->_start, 0, 0, 1, 1);
	layout->addWidget(this->_die, 1, 0, 1, 1);
	layout->addWidget(this->_bonusFactor, 2, 0, 1, 1);
	layout->addWidget(this->_malus, 3, 0, 1, 1);
	layout->addWidget(this->_min_features, 4, 0, 1, 1);

	QObject::connect(this->_start, SIGNAL(valueChanged(int)), this, SIGNAL(startChanged(int)));
	QObject::connect(this->_die, SIGNAL(valueChanged(int)), this, SIGNAL(dieChanged(int)));
	QObject::connect(this->_bonusFactor, SIGNAL(valueChanged(int)), this, SIGNAL(bonusFactorChanged(int)));
	QObject::connect(this->_malus, SIGNAL(valueChanged(int)), this, SIGNAL(malusChanged(int)));
	QObject::connect(this->_min_features, SIGNAL(valueChanged(int)), this, SIGNAL(minFeaturesChanged(int)));
}

void TrustTab::loadParameters(const CondensationParameters &parameters){
	this->_start->setValue(parameters.TRUST_START);
	this->_die->setValue(parameters.TRUST_DIE);
	this->_bonusFactor->setValue(parameters.TRUST_BONUS_FACTOR);
	this->_malus->setValue(parameters.TRUST_MALUS);
	this->_min_features->setValue(parameters.MIN_FEATURES);
}
