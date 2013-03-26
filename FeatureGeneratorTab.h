#ifndef FEATUREGENERATORTAB_H
#define FEATUREGENERATORTAB_H

#include <QWidget>
#include "CustomDial.h"
#include "CustomToggle.h"
#include "CondensationParameters.h"

class FeatureGeneratorTab : public QWidget{
	Q_OBJECT
private:
	CustomDial* _maxCorners = new CustomDial("Max corners", 1, 100);
	CustomDial* _qualityLevel = new CustomDial("Quality level", 0, 100);
	CustomDial* _minDistance = new CustomDial("Min distance", 0, 1000);
	CustomDial* _blockSize = new CustomDial("Block size", 0, 1000);
	CustomToggle* _useHarrisDetector = new CustomToggle("Use harris detector");
	CustomDial* _k = new CustomDial("K", 0, 100);
public:
	explicit FeatureGeneratorTab(QWidget *parent = 0);
	void loadParameters(const CondensationParameters& parameters);
	
signals:
	
public slots:
	
};

#endif // FEATUREGENERATORTAB_H
