#ifndef INPUTOUTPUTTAB_H
#define INPUTOUTPUTTAB_H

#include <QWidget>

#include <QPushButton>
#include <QGridLayout>

class InputOutputTab : public QWidget{
	Q_OBJECT
private:
	QPushButton* _save = new QPushButton("Save");
	QPushButton* _load = new QPushButton("Load");
	QGridLayout* _layout = new QGridLayout(this);
public:
	explicit InputOutputTab(QWidget *parent = 0);
	
signals:
	void save();
	void load();
public slots:
	
};

#endif // INPUTOUTPUTTAB_H
