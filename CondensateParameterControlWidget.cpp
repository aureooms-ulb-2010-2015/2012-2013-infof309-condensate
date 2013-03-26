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
