#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "BasicWindow.h"
#include "CustomButton.h"

class MainWindow : public BasicWindow{
    Q_OBJECT

private:
	CustomButton* _parameterToggle = new CustomButton();

	void initProcessingChoices();
	virtual FrameProcessor* generateProcessor();
    
public:
    explicit MainWindow(QWidget *parent = 0);
	virtual ~MainWindow();

};

#endif // MAINWINDOW_H
