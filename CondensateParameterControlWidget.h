#ifndef CONDENSATEPARAMETERCONTROLWIDGET_H
#define CONDENSATEPARAMETERCONTROLWIDGET_H

#include <QDialog>
#include <QTabWidget>
#include "DensityTab.h"
#include "FeatureGeneratorTab.h"
#include "MatcherTab.h"
#include "PrecisionTab.h"
#include "SegmentationTab.h"
#include "CondensationParameters.h"
#include "InputOutputTab.h"
#include "TrustTab.h"

class CondensateParameterControlDialog : public QDialog{
	Q_OBJECT
private:
    QTabWidget* _tabs = new QTabWidget(this);
    DensityTab* _densityTab = new DensityTab();
    FeatureGeneratorTab* _featureGeneratorTab = new FeatureGeneratorTab();
    MatcherTab* _matcherTab = new MatcherTab();
	PrecisionTab* _precisionTab = new PrecisionTab();
	SegmentationTab* _segmentationTab = new SegmentationTab();
	InputOutputTab* _inputOutputTab = new InputOutputTab();
	TrustTab* _trustTab = new TrustTab();
public:
	CondensateParameterControlDialog(QWidget* parent = 0);
	void loadParameters(const CondensationParameters& parameters);

public slots:
	void save();
	void load();

signals:

	void spreadRangeChanged(int);
	void maxCornersChanged(int);
	void qualityLevelChanged(float);
	void minDistanceChanged(int);
	void blockSizeChanged(int);
	void kChanged(float);
	void useHarrisDetectorChanged(bool);
	void maxDistChanged(int);
	void pollingRangeChanged(int);
	void generatingRangeChanged(int);
	void minWidthChanged(int);
	void maxWidthChanged(int);
	void minHeightChanged(int);
	void maxHeightChanged(int);
	void minAccumulatorIterationsChanged(int);
	void radiusChanged(int);
	void matcherTypeChanged(int);
	void startChanged(int);
	void dieChanged(int);
	void bonusFactorChanged(int);
	void malusChanged(int);
	void minFeaturesChanged(int);
	void resamplingPassesChanged(int);
	void resamplingRangeChanged(int);
};

#endif // CONDENSATEPARAMETERCONTROLWIDGET_H
