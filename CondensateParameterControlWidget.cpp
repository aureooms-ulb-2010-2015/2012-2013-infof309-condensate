#include "CondensateParameterControlWidget.h"
#include <QGridLayout>
#include "CustomDial.h"
CondensateParameterControlDialog::CondensateParameterControlDialog(QWidget *parent) : QDialog(parent){
	this->_tabs->addTab(this->_thresholdsTab, "Thresholds");
	this->_tabs->addTab(new QWidget(), "Other");
	QGridLayout* layout = new QGridLayout(this->_thresholdsTab);
    layout->addWidget(new CustomDial("Min size", 1, 640), 0, 0, 1, 1);
    this->_tabs->setFixedSize(480,480);

	this->setWindowTitle("ConDensAte - parameters");
}
