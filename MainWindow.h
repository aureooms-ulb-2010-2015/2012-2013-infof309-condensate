#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "BasicWindow.h"
#include "CustomButton.h"
#include "CondensateParameterControlWidget.h"
#include "Algorithm_CustomCondensationTemplateV3.h"
#include "Algorithm_SynchronizedCondensation.h"

class MainWindow : public BasicWindow{
    Q_OBJECT

private:
	CustomButton* _parameterToggle = new CustomButton();
	CondensateParameterControlDialog* _parameterControlWidget = new CondensateParameterControlDialog(this);

	void initProcessingChoices();
	virtual FrameProcessor* generateProcessor();
    
public:
    explicit MainWindow(QWidget *parent = 0);
	virtual ~MainWindow();
	SynchronizedCondensation<CustomCondensationTemplateV3>* getSynchronizedAlgorithm();

	void splitScreen();
	void keyPressEvent(QKeyEvent *event);
public slots:
	virtual void toggleParameterControlWidget();


	void spreadRangeChangedSLOT(int);
	void maxCornersChangedSLOT(int);
	void qualityLevelChangedSLOT(float);
	void minDistanceChangedSLOT(int);
	void blockSizeChangedSLOT(int);
	void kChangedSLOT(float);
	void useHarrisDetectorChangedSLOT(bool);
	void maxDistChangedSLOT(int);
	void radiusChangedSLOT(int);
	void pollingRangeChangedSLOT(int);
	void generatingRangeChangedSLOT(int);
	void minWidthChangedSLOT(int);
	void maxWidthChangedSLOT(int);
	void minHeightChangedSLOT(int);
	void maxHeightChangedSLOT(int);
	void minAccumulatorIterationsChangedSLOT(int);
	void matcherTypeChangedSLOT(int);
	void startChangedSLOT(int);
	void dieChangedSLOT(int);
	void bonusFactorChangedSLOT(int);
	void malusChangedSLOT(int);
	void minFeaturesChangedSLOT(int);
	void resamplingPassesChangedSLOT(int);
	void resamplingRangeChangedSLOT(int);
};

#endif // MAINWINDOW_H
