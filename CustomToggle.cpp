#include "CustomToggle.h"

CustomToggle::CustomToggle(const QString &labelText, QWidget *parent) : QWidget(parent){
	layout->addWidget(label, 0, 0, 1, 1);
	layout->addWidget(input, 0, 1, 1, 3);
	label->setText(labelText);
	QObject::connect(input, SIGNAL(toggled(bool)), this, SIGNAL(toggled(bool)));
}

void CustomToggle::setToggled(bool toggled){
	input->setChecked(toggled);
}
