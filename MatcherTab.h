#ifndef MATCHERTAB_H
#define MATCHERTAB_H
#include <QWidget>
#include "CustomDial.h"

class MatcherTab : public QWidget
{
	Q_OBJECT
private:
	CustomDial* _maxDist = new CustomDial("Max distance", 0, 1000);
public:
	explicit MatcherTab(QWidget *parent = 0);

signals:

public slots:

};

#endif // MATCHERTAB_H
