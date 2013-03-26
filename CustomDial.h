#ifndef CUSTOMDIAL_H
#define CUSTOMDIAL_H

#include <QWidget>
#include <QLabel>
#include <QDial>
#include <QGridLayout>

class CustomDial : public QWidget{
    Q_OBJECT

private:
    QLabel* label = new QLabel();
    QDial* input = new QDial();
    QLabel* value = new QLabel();
    QGridLayout* layout = new QGridLayout(this);
public:
    explicit CustomDial(const QString &labelText, int minValue, int maxValue, QWidget *parent = 0);
    void setValue(int);
    void setValueText(int newValue);
signals:
    void valueChanged(int);
    
public slots:

    void valueChangedSLOT(int);
    void changeLowerBoundSLOT(int);
    void changeUpperBoundSLOT(int);
    
};

#endif // CUSTOMDIAL_H
