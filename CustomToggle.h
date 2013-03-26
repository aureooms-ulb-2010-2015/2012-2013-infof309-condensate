#ifndef CUSTOMTOGGLE_H
#define CUSTOMTOGGLE_H

#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QGridLayout>
#include <QObject>

class CustomToggle : public QWidget{
Q_OBJECT
private:

	QLabel* label = new QLabel();
	QCheckBox* input = new QCheckBox();
	QGridLayout* layout = new QGridLayout(this);

public:
	explicit CustomToggle(const QString &labelText, QWidget *parent = 0);
	CustomToggle();
	void setToggled(bool);

signals:
	void toggled(bool);
};

#endif // CUSTOMTOGGLE_H
