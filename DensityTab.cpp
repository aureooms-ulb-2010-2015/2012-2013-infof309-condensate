#include "DensityTab.h"

DensityTab::DensityTab(QWidget *parent) :
	QWidget(parent)
{
	QGridLayout* layout = new QGridLayout(this);
	layout->addWidget(this->_spreadRange, 0, 0, 1, 1);
}
