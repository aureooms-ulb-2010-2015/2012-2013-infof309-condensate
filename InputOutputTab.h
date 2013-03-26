#ifndef INPUTOUTPUTTAB_H
#define INPUTOUTPUTTAB_H

#include <QWidget>

#include <QPushButton>
#include <QGridLayout>

class InputOutputTab : public QWidget
{
	Q_OBJECT
private:
	QPushButton* save = new QPushButton("Save");
	QPushButton* load = new QPushButton("Load");
	QGridLayout* layout = new QGridLayout(this);
public:
	explicit InputOutputTab(QWidget *parent = 0);
	
signals:
	
public slots:
	
};

#endif // INPUTOUTPUTTAB_H
