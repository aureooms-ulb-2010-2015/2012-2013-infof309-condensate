#ifndef CONDENSATEPARAMETERCONTROLWIDGET_H
#define CONDENSATEPARAMETERCONTROLWIDGET_H

#include <QDialog>
#include <QTabWidget>

class CondensateParameterControlDialog : public QDialog{
private:
	QTabWidget* _tabs = new QTabWidget(this);
	QWidget* _thresholdsTab = new QWidget();
public:
	CondensateParameterControlDialog(QWidget* parent = 0);
};

#endif // CONDENSATEPARAMETERCONTROLWIDGET_H
