#include "CondensateParameterControlWidget.h"
CondensateParameterControlDialog::CondensateParameterControlDialog(QWidget *parent) : QDialog(parent){
    this->_tabs->addTab(this->_densityTab, "Density");
    this->_tabs->addTab(this->_featureGeneratorTab, "Feature Generator");
    this->_tabs->addTab(this->_matcherTab, "Matcher");
    this->_tabs->addTab(this->_precisionTab, "Precision");
    this->_tabs->addTab(this->_segmentationTab, "Segmentation");
	this->_tabs->setFixedSize(480,480);
	this->setWindowTitle("Parameters Controls");
}

void CondensateParameterControlDialog::loadParameters(const CondensationParameters &parameters){
	this->_densityTab->loadParameters(parameters);
	this->_featureGeneratorTab->loadParameters(parameters);
	this->_matcherTab->loadParameters(parameters);
	this->_precisionTab->loadParameters(parameters);
	this->_segmentationTab->loadParameters(parameters);
}
