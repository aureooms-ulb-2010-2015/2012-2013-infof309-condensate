#include "CustomSelect.h"

CustomSelect::CustomSelect(const QString &labelText, const std::vector<QString>& entries, QWidget *parent) : QWidget(parent){
  layout->addWidget(label, 0, 0, 1, 1);
  layout->addWidget(input, 0, 1, 1, 3);
  label->setText(labelText);
  for(const QString& entry : entries){
	  input->addItem(entry);
  }
  QObject::connect(input, SIGNAL(currentIndexChanged(int)), this, SIGNAL(currentIndexChanged(int)));
}

void CustomSelect::setCurrentIndex(int index){
  input->setCurrentIndex(index);
}
