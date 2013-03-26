#include "SegmentationTab.h"
#include <QGridLayout>

SegmentationTab::SegmentationTab(QWidget *parent) :
	QWidget(parent)
{
    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(this->_minWidth, 0, 0, 1, 1);
    layout->addWidget(this->_maxWidth, 1, 0, 1, 1);
    layout->addWidget(this->_minHeight, 2, 0, 1, 1);
    layout->addWidget(this->_maxHeight, 3, 0, 1, 1);

    QObject::connect(this->_minWidth, SIGNAL(valueChanged(int)), this->_maxWidth, SLOT(changeLowerBoundSLOT(int)));
    QObject::connect(this->_maxWidth, SIGNAL(valueChanged(int)), this->_minWidth, SLOT(changeUpperBoundSLOT(int)));
    QObject::connect(this->_minHeight, SIGNAL(valueChanged(int)), this->_maxHeight, SLOT(changeLowerBoundSLOT(int)));
    QObject::connect(this->_maxHeight, SIGNAL(valueChanged(int)), this->_minHeight, SLOT(changeUpperBoundSLOT(int)));
}
