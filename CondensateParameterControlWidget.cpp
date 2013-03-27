#include "CondensateParameterControlWidget.h"

CondensateParameterControlDialog::CondensateParameterControlDialog(QWidget *parent) : QDialog(parent){
    this->_tabs->addTab(this->_densityTab, "Density");
    this->_tabs->addTab(this->_featureGeneratorTab, "Feature Generator");
    this->_tabs->addTab(this->_matcherTab, "Matcher");
	this->_tabs->addTab(this->_precisionTab, "Precision");
	this->_tabs->addTab(this->_segmentationTab, "Segmentation");
	this->_tabs->addTab(this->_inputOutputTab, "XML");
	this->_tabs->setFixedSize(560,480);
	this->setWindowTitle("Parameters Controls");

	QObject::connect(this->_inputOutputTab, SIGNAL(save()), this, SLOT(save()));
	QObject::connect(this->_inputOutputTab, SIGNAL(load()), this, SLOT(load()));

	QObject::connect(this->_densityTab, SIGNAL(spreadRangeChanged(int)), this, SIGNAL(spreadRangeChanged(int)));
	QObject::connect(this->_featureGeneratorTab, SIGNAL(maxCornersChanged(int)), this, SIGNAL(maxCornersChanged(int)));
	QObject::connect(this->_featureGeneratorTab, SIGNAL(qualityLevelChanged(float)), this, SIGNAL(qualityLevelChanged(float)));
	QObject::connect(this->_featureGeneratorTab, SIGNAL(minDistanceChanged(int)), this, SIGNAL(minDistanceChanged(int)));
	QObject::connect(this->_featureGeneratorTab, SIGNAL(blockSizeChanged(int)), this, SIGNAL(blockSizeChanged(int)));
	QObject::connect(this->_featureGeneratorTab, SIGNAL(kChanged(float)), this, SIGNAL(kChanged(float)));
	QObject::connect(this->_featureGeneratorTab, SIGNAL(useHarrisDetectorChanged(bool)), this, SIGNAL(useHarrisDetectorChanged(bool)));
	QObject::connect(this->_matcherTab, SIGNAL(maxDistChanged(int)), this, SIGNAL(maxDistChanged(int)));
	QObject::connect(this->_matcherTab, SIGNAL(radiusChanged(int)), this, SIGNAL(radiusChanged(int)));
	QObject::connect(this->_precisionTab, SIGNAL(pollingRangeChanged(int)), this, SIGNAL(pollingRangeChanged(int)));
	QObject::connect(this->_precisionTab, SIGNAL(generatingRangeChanged(int)), this, SIGNAL(generatingRangeChanged(int)));
	QObject::connect(this->_segmentationTab, SIGNAL(minWidthChanged(int)), this, SIGNAL(minWidthChanged(int)));
	QObject::connect(this->_segmentationTab, SIGNAL(maxWidthChanged(int)), this, SIGNAL(maxWidthChanged(int)));
	QObject::connect(this->_segmentationTab, SIGNAL(minHeightChanged(int)), this, SIGNAL(minHeightChanged(int)));
	QObject::connect(this->_segmentationTab, SIGNAL(maxHeightChanged(int)), this, SIGNAL(maxHeightChanged(int)));
	QObject::connect(this->_segmentationTab, SIGNAL(minAccumulatorIterationsChanged(int)), this, SIGNAL(minAccumulatorIterationsChanged(int)));
}

void CondensateParameterControlDialog::loadParameters(const CondensationParameters &parameters){
	this->_densityTab->loadParameters(parameters);
	this->_featureGeneratorTab->loadParameters(parameters);
	this->_matcherTab->loadParameters(parameters);
	this->_precisionTab->loadParameters(parameters);
	this->_segmentationTab->loadParameters(parameters);
}

void CondensateParameterControlDialog::save(){
	//TODO
}

void CondensateParameterControlDialog::load(){
	//TODO
}
