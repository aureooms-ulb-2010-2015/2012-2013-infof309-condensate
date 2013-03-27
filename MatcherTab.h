#ifndef MATCHERTAB_H
#define MATCHERTAB_H
#include <QWidget>
#include "CustomDial.h"
#include "CondensationParameters.h"
#include "CustomSelect.h"

class MatcherTab : public QWidget{
	Q_OBJECT
private:
	std::vector<QString> types = {"Color", "Gradient"};
	CustomSelect* _matcherType = new CustomSelect("Matcher type", types);
	CustomDial* _maxDist = new CustomDial("Max distance", 0, 1000);
	CustomDial* _radius = new CustomDial("Radius", 0, 239);
public:
	explicit MatcherTab(QWidget *parent = 0);
	void loadParameters(const CondensationParameters& parameters);

signals:
	void maxDistChanged(int);
	void radiusChanged(int);
	void matcherTypeChanged(int);

public slots:

};

#endif // MATCHERTAB_H
