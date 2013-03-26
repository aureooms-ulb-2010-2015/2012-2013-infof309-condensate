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
public slots:
	virtual void toggleParameterControlWidget();
};

#endif // MAINWINDOW_H
