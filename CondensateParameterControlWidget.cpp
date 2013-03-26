#include "CondensateParameterControlWidget.h"
#include <QGridLayout>
#include "CustomDial.h"
CondensateParameterControlDialog::CondensateParameterControlDialog(QWidget *parent) : QDialog(parent){
	this->_tabs->addTab(this->_thresholdsTab, "Thresholds");
	this->_tabs->addTab(new QWidget(), "Other");
<<<<<<< HEAD
    this->_tabs->addTab(this->_otherTab, "Other");
    QGridLayout* layout = new QGridLayout(this->_thresholdsTab);
    QGridLayout* layout2 = new QGridLayout(this->_otherTab);
    layout->addWidget(new QDial(), 0, 0, 1, 1);
	this->_tabs->setFixedSize(480,480);
=======
	QGridLayout* layout = new QGridLayout(this->_thresholdsTab);
    layout->addWidget(new CustomDial("Min size", 1, 640), 0, 0, 1, 1);
    this->_tabs->setFixedSize(480,480);

>>>>>>> d2354505d629d67476d61d8c264eb93a498d2d7a
	this->setWindowTitle("ConDensAte - parameters");
}
