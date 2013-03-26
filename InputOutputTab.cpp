#include "InputOutputTab.h"

InputOutputTab::InputOutputTab(QWidget *parent) :
	QWidget(parent){
	layout->addWidget(save,0, 1, 1, 1);
	layout->addWidget(load,1, 1, 1, 1);

	save->setFixedSize(150, 100);
	save->setFont(QFont(save->font().family(), 12, QFont::Bold));
	load->setFixedSize(150, 100);
	load->setFont(QFont(load->font().family(), 12, QFont::Bold));
}
