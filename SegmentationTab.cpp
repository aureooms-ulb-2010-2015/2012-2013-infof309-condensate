#include "SegmentationTab.h"
#include <QGridLayout>

SegmentationTab::SegmentationTab(QWidget *parent) :
	QWidget(parent){
    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(this->_minWidth, 0, 0, 1, 1);
    layout->addWidget(this->_maxWidth, 1, 0, 1, 1);
    layout->addWidget(this->_minHeight, 2, 0, 1, 1);
	layout->addWidget(this->_maxHeight, 3, 0, 1, 1);
	layout->addWidget(this->_min_acc_iterations, 4, 0, 1, 1);

    QObject::connect(this->_minWidth, SIGNAL(valueChanged(int)), this->_maxWidth, SLOT(changeLowerBoundSLOT(int)));
    QObject::connect(this->_maxWidth, SIGNAL(valueChanged(int)), this->_minWidth, SLOT(changeUpperBoundSLOT(int)));
    QObject::connect(this->_minHeight, SIGNAL(valueChanged(int)), this->_maxHeight, SLOT(changeLowerBoundSLOT(int)));
	QObject::connect(this->_maxHeight, SIGNAL(valueChanged(int)), this->_minHeight, SLOT(changeUpperBoundSLOT(int)));
}

void SegmentationTab::loadParameters(const CondensationParameters &parameters){
	this->_minWidth->setValue(parameters.TARGET_MIN_WIDTH);
	this->_maxWidth->setValue(parameters.TARGET_MAX_WIDTH);
	this->_minHeight->setValue(parameters.TARGET_MIN_HEIGHT);
	this->_maxHeight->setValue(parameters.TARGET_MAX_HEIGHT);
	this->_min_acc_iterations->setValue(parameters.MIN_ACCUMULATOR_ITERATIONS);
}
