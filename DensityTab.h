#ifndef DENSITYTAB_H
#define DENSITYTAB_H

#include <QWidget>
#include "CustomDial.h"
#include "CondensationParameters.h"

class DensityTab : public QWidget{
	Q_OBJECT
private:
	CustomDial* _spreadRange = new CustomDial("Spread range", 0, 100);
	CustomDial* _resamplingPasses = new CustomDial("Resampling passes", 0, 100);
	CustomDial* _resamplingRange = new CustomDial("Resampling range", 0, 100);
public:
	explicit DensityTab(QWidget *parent = 0);
	void loadParameters(const CondensationParameters& parameters);
	
signals:

	void spreadRangeChanged(int);
	void resamplingPassesChanged(int);
	void resamplingRangeChanged(int);
	
public slots:
	
};

#endif // DENSITYTAB_H
