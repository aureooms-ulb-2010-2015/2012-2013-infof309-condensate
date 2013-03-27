#ifndef FEATUREGENERATORTAB_H
#define FEATUREGENERATORTAB_H

#include <QWidget>
#include "CustomDial.h"
#include "CustomToggle.h"
#include "CondensationParameters.h"

class FeatureGeneratorTab : public QWidget{
	Q_OBJECT
private:
	const float PRECISION = 100;

	CustomDial* _maxCorners = new CustomDial("Max corners", 1, 100);
	CustomDial* _qualityLevel = new CustomDial("Quality level", 1, PRECISION);
	CustomDial* _minDistance = new CustomDial("Min distance", 0, 1000);
	CustomDial* _blockSize = new CustomDial("Block size", 1, 1000);
	CustomToggle* _useHarrisDetector = new CustomToggle("Use harris detector");
	CustomDial* _k = new CustomDial("K", 0, PRECISION);

public:
	explicit FeatureGeneratorTab(QWidget *parent = 0);
	void loadParameters(const CondensationParameters& parameters);
	
signals:
	void maxCornersChanged(int);
	void qualityLevelChanged(float);
	void minDistanceChanged(int);
	void blockSizeChanged(int);
	void useHarrisDetectorChanged(bool);
	void kChanged(float);
	
public slots:
	void qualityLevelChangedSLOT(int);
	void kChangedSLOT(int);
	
};

#endif // FEATUREGENERATORTAB_H
