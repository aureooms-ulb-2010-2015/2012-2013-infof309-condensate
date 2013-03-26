#include "FeatureGeneratorTab.h"

FeatureGeneratorTab::FeatureGeneratorTab(QWidget *parent) :
	QWidget(parent)
{
	QGridLayout* layout = new QGridLayout(this);
	layout->addWidget(this->_maxCorners, 0, 0, 1, 1);
	layout->addWidget(this->_qualityLevel, 1, 0, 1, 1);
	layout->addWidget(this->_minDistance, 2, 0, 1, 1);
	layout->addWidget(this->_blockSize, 3, 0, 1, 1);
	layout->addWidget(this->_useHarrisDetector, 4, 0, 1, 1);
	layout->addWidget(this->_k, 5, 0, 1, 1);
}
