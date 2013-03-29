#include "CondensateParameterControlWidget.h"

CondensateParameterControlDialog::CondensateParameterControlDialog(QWidget *parent) : QDialog(parent){
    this->_tabs->addTab(this->_densityTab, "Density");
    this->_tabs->addTab(this->_featureGeneratorTab, "Feature Generator");
    this->_tabs->addTab(this->_matcherTab, "Matcher");
	this->_tabs->addTab(this->_precisionTab, "Precision");
	this->_tabs->addTab(this->_segmentationTab, "Segmentation");
	this->_tabs->addTab(this->_trustTab, "Trust");
	this->_tabs->addTab(this->_inputOutputTab, "XML");
	this->_tabs->setFixedSize(600,480);
	this->setWindowTitle("Parameters Controls");

	QObject::connect(this->_inputOutputTab, SIGNAL(save()), this, SIGNAL(save()));
	QObject::connect(this->_inputOutputTab, SIGNAL(load()), this, SIGNAL(load()));

	QObject::connect(this->_densityTab, SIGNAL(spreadRangeChanged(int)), this, SIGNAL(spreadRangeChanged(int)));
	QObject::connect(this->_densityTab, SIGNAL(resamplingPassesChanged(int)), this, SIGNAL(resamplingPassesChanged(int)));
	QObject::connect(this->_densityTab, SIGNAL(resamplingRangeChanged(int)), this, SIGNAL(resamplingRangeChanged(int)));
	QObject::connect(this->_featureGeneratorTab, SIGNAL(maxCornersChanged(int)), this, SIGNAL(maxCornersChanged(int)));
	QObject::connect(this->_featureGeneratorTab, SIGNAL(qualityLevelChanged(float)), this, SIGNAL(qualityLevelChanged(float)));
	QObject::connect(this->_featureGeneratorTab, SIGNAL(minDistanceChanged(int)), this, SIGNAL(minDistanceChanged(int)));
	QObject::connect(this->_featureGeneratorTab, SIGNAL(blockSizeChanged(int)), this, SIGNAL(blockSizeChanged(int)));
	QObject::connect(this->_featureGeneratorTab, SIGNAL(kChanged(float)), this, SIGNAL(kChanged(float)));
	QObject::connect(this->_featureGeneratorTab, SIGNAL(useHarrisDetectorChanged(bool)), this, SIGNAL(useHarrisDetectorChanged(bool)));
	QObject::connect(this->_matcherTab, SIGNAL(matcherTypeChanged(int)), this, SIGNAL(matcherTypeChanged(int)));
	QObject::connect(this->_matcherTab, SIGNAL(maxDistChanged(int)), this, SIGNAL(maxDistChanged(int)));
	QObject::connect(this->_matcherTab, SIGNAL(radiusChanged(int)), this, SIGNAL(radiusChanged(int)));
	QObject::connect(this->_precisionTab, SIGNAL(pollingRangeChanged(int)), this, SIGNAL(pollingRangeChanged(int)));
	QObject::connect(this->_precisionTab, SIGNAL(generatingRangeChanged(int)), this, SIGNAL(generatingRangeChanged(int)));
	QObject::connect(this->_segmentationTab, SIGNAL(minWidthChanged(int)), this, SIGNAL(minWidthChanged(int)));
	QObject::connect(this->_segmentationTab, SIGNAL(maxWidthChanged(int)), this, SIGNAL(maxWidthChanged(int)));
	QObject::connect(this->_segmentationTab, SIGNAL(minHeightChanged(int)), this, SIGNAL(minHeightChanged(int)));
	QObject::connect(this->_segmentationTab, SIGNAL(maxHeightChanged(int)), this, SIGNAL(maxHeightChanged(int)));
	QObject::connect(this->_segmentationTab, SIGNAL(minAccumulatorIterationsChanged(int)), this, SIGNAL(minAccumulatorIterationsChanged(int)));
	QObject::connect(this->_trustTab, SIGNAL(startChanged(int)), this, SIGNAL(startChanged(int)));
	QObject::connect(this->_trustTab, SIGNAL(dieChanged(int)), this, SIGNAL(dieChanged(int)));
	QObject::connect(this->_trustTab, SIGNAL(bonusFactorChanged(int)), this, SIGNAL(bonusFactorChanged(int)));
	QObject::connect(this->_trustTab, SIGNAL(malusChanged(int)), this, SIGNAL(malusChanged(int)));
	QObject::connect(this->_trustTab, SIGNAL(minFeaturesChanged(int)), this, SIGNAL(minFeaturesChanged(int)));
}

void CondensateParameterControlDialog::loadParameters(const CondensationParameters &parameters){
	this->_densityTab->loadParameters(parameters);
	this->_featureGeneratorTab->loadParameters(parameters);
	this->_matcherTab->loadParameters(parameters);
	this->_precisionTab->loadParameters(parameters);
	this->_segmentationTab->loadParameters(parameters);
	this->_trustTab->loadParameters(parameters);
}

