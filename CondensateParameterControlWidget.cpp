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
