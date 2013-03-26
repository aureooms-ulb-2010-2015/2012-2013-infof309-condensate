#include "InputOutputTab.h"

InputOutputTab::InputOutputTab(QWidget *parent) :
	QWidget(parent){
	_layout->addWidget(this->_save,0, 1, 1, 1);
	_layout->addWidget(this->_load,1, 1, 1, 1);

	this->_save->setFixedSize(150, 100);
	this->_save->setFont(QFont(this->_save->font().family(), 12, QFont::Bold));
	this->_load->setFixedSize(150, 100);
	this->_load->setFont(QFont(this->_load->font().family(), 12, QFont::Bold));

	QObject::connect(this->_save, SIGNAL(clicked()), this, SIGNAL(save()));
	QObject::connect(this->_load, SIGNAL(clicked()), this, SIGNAL(load()));
}
