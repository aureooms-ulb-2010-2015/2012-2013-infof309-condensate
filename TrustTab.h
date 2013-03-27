#ifndef TRUSTTAB_H
#define TRUSTTAB_H

#include <QWidget>
#include "CustomDial.h"
#include "CondensationParameters.h"

class TrustTab : public QWidget{
	Q_OBJECT
private:
	CustomDial* _start = new CustomDial("Start", 0, 1000);
	CustomDial* _die = new CustomDial("Die", 0, 1000);
	CustomDial* _bonusFactor = new CustomDial("Bonus factor", 1, 200);
	CustomDial* _malus = new CustomDial("Malus", 1, 1000);
	CustomDial* _min_features = new CustomDial("Min features", 1, 100);
public:
	explicit TrustTab(QWidget *parent = 0);
	void loadParameters(const CondensationParameters& parameters);

signals:
	void startChanged(int);
	void dieChanged(int);
	void bonusFactorChanged(int);
	void malusChanged(int);
	void minFeaturesChanged(int);

public slots:

};

#endif // TRUSTTAB_H
