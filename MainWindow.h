#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "BasicWindow.h"
#include "CustomButton.h"
#include "CondensateParameterControlWidget.h"

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

public slots:
	virtual void toggleParameterControlWidget();
};

#endif // MAINWINDOW_H
