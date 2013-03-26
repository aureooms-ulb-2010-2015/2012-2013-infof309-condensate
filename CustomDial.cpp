#include "CustomDial.h"
#include <sstream>
CustomDial::CustomDial(const QString& labelText, int minValue, int maxValue, QWidget *parent) :
    QWidget(parent){
        layout->addWidget(label, 0, 0, 1, 1);
        layout->addWidget(input, 0, 1, 1, 1);
        layout->addWidget(value, 0, 2, 1, 1);
        layout->addWidget(bounds, 0, 3, 1, 1);


        input->setMinimum(minValue);
		this->setValueText(minValue);
        input->setMaximum(maxValue);
        this->refreshBoundText();
        label->setText(labelText);

		QObject::connect(input, SIGNAL(valueChanged(int)), this, SLOT(valueChangedSLOT(int)));

}

void CustomDial::setValue(int newValue){
    input->setValue(newValue);
    //this->setValueText(newValue);
}


void CustomDial::valueChangedSLOT(int newValue){
    this->setValueText(newValue);
    emit valueChanged(newValue);
}

void CustomDial::changeLowerBoundSLOT(int bound)
{
    this->input->setMinimum(bound);
    this->refreshBoundText();
}

void CustomDial::setValueText(int newValue){
    std::ostringstream text;
    text << newValue;
    value->setText(QString(text.str().c_str()));
}


void CustomDial::changeUpperBoundSLOT(int bound)
{
    this->input->setMaximum(bound);
    this->refreshBoundText();
}


void CustomDial::refreshBoundText()
{
    std::ostringstream text;
    text << "(" << input->minimum() << " - " << input->maximum() << ")";
    bounds->setText(QString(text.str().c_str()));
}
