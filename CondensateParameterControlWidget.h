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

class CondensateParameterControlDialog : public QDialog{
private:
    QTabWidget* _tabs = new QTabWidget(this);
    DensityTab* _densityTab = new DensityTab();
    FeatureGeneratorTab* _featureGeneratorTab = new FeatureGeneratorTab();
    MatcherTab* _matcherTab = new MatcherTab();
	PrecisionTab* _precisionTab = new PrecisionTab();
	SegmentationTab* _segmentationTab = new SegmentationTab();
	InputOutputTab* _inputOutputTab = new InputOutputTab();
public:
	CondensateParameterControlDialog(QWidget* parent = 0);
	void loadParameters(const CondensationParameters& parameters);
};

#endif // CONDENSATEPARAMETERCONTROLWIDGET_H
