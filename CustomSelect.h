#ifndef CUSTOMSELECT_H
#define CUSTOMSELECT_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QGridLayout>
#include <vector>

class CustomSelect : public QWidget{
	Q_OBJECT
private:
	QLabel* label = new QLabel();
	QComboBox* input = new QComboBox();
	QGridLayout* layout = new QGridLayout(this);
public:
	explicit CustomSelect(const QString& labelText, const std::vector<QString>& entries,  QWidget *parent = 0);
	void setCurrentIndex(int index);

signals:
	void currentIndexChanged(int);
public slots:
	
};

#endif // CUSTOMSELECT_H
