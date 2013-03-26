#include "CondensateParameterControlWidget.h"
#include <QGridLayout>
#include <QDial>
CondensateParameterControlDialog::CondensateParameterControlDialog(QWidget *parent) : QDialog(parent){
	this->_tabs->addTab(this->_thresholdsTab, "Thresholds");
	this->_tabs->addTab(new QWidget(), "Other");
    this->_tabs->addTab(this->_otherTab, "Other");
    QGridLayout* layout = new QGridLayout(this->_thresholdsTab);
    QGridLayout* layout2 = new QGridLayout(this->_otherTab);
    layout->addWidget(new QDial(), 0, 0, 1, 1);
	this->_tabs->setFixedSize(480,480);
	this->setWindowTitle("ConDensAte - parameters");
}
