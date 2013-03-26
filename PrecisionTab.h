#ifndef PRECISIONTAB_H
#define PRECISIONTAB_H

#include <QWidget>
#include "CustomDial.h"

class PrecisionTab : public QWidget
{
	Q_OBJECT
private:
	CustomDial* _pollingRange = new CustomDial("Polling range", 1, 100);
	CustomDial* _generatingRange = new CustomDial("Genrating range", 0, 1000);
public:
	explicit PrecisionTab(QWidget *parent = 0);
	
signals:
	
public slots:
	
};

#endif // PRECISIONTAB_H
