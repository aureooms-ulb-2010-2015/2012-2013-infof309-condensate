#ifndef FEATUREGENERATORTAB_H
#define FEATUREGENERATORTAB_H

#include <QWidget>
#include "CustomDial.h"

class FeatureGeneratorTab : public QWidget
{
	Q_OBJECT
private:
	CustomDial* _maxCorners = new CustomDial("Max corners", 1, 100);
	CustomDial* _qualityLevel = new CustomDial("Quality level", 0, 1000);
	CustomDial* _minDistance = new CustomDial("Min distance", 0, 1000);
	CustomDial* _blockSize = new CustomDial("Block size", 0, 1000);
	CustomDial* _useHarrisDetector = new CustomDial("Use harris detector", 0, 1);
	CustomDial* _k = new CustomDial("K", 0, 100);
public:
	explicit FeatureGeneratorTab(QWidget *parent = 0);
	
signals:
	
public slots:
	
};

#endif // FEATUREGENERATORTAB_H
