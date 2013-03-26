#include "MainWindow.h"

#include <QApplication>
#include <QDesktopWidget>

//===================================================

FrameProcessor* MainWindow::generateProcessor(){
	this->_frameProcessor = new SynchronizedCondensation<CustomCondensationTemplateV3>();
	this->_parameterControlWidget->loadParameters(this->getSynchronizedAlgorithm()->getActualParameters());
	return this->_frameProcessor;
}

MainWindow::MainWindow(QWidget *parent) : BasicWindow(parent){
        this->setWindowTitle("ConDensAte");

        QGridLayout* upperBarLayout = new QGridLayout(this->_upperBar);
        upperBarLayout->addWidget(this->_inputChoice, 0, 0, 1, 3);
        upperBarLayout->addWidget(this->_parameterToggle, 0, 3, 1, 1);
        this->_parameterToggle->setFixedHeight(23);
        this->_parameterToggle->setIcon(QIcon(":parameter_icon"));
        upperBarLayout->setContentsMargins(0,0,0,0);

        QObject::connect(this->_parameterToggle, SIGNAL(clicked()), this, SLOT(toggleParameterControlWidget()));
}

MainWindow::~MainWindow(){}

SynchronizedCondensation<CustomCondensationTemplateV3> *MainWindow::getSynchronizedAlgorithm(){
	return (SynchronizedCondensation<CustomCondensationTemplateV3>*) this->_frameProcessor;
}

void MainWindow::toggleParameterControlWidget(){
        if(this->_parameterControlWidget->isVisible()){
			this->_parameterControlWidget->hide();
			if(!this->isFullScreen()){
				this->centerWindow();
			}
        }
        else{
			this->_parameterControlWidget->show();
			if(!this->isFullScreen()){
				this->splitScreen();
			}
        }
}


void MainWindow::splitScreen(){
	this->show();
	QRect leftRect(this->frameGeometry()), rightRect(this->_parameterControlWidget->frameGeometry());
	QPoint leftCenter, rightCenter, screenCenter;
	screenCenter = QApplication::desktop()->availableGeometry().center();
	leftCenter.setX(screenCenter.x()/2);
	leftCenter.setY(screenCenter.y());
	rightCenter.setX(screenCenter.x()*3/2);
	rightCenter.setY(screenCenter.y());
	leftRect.moveCenter(leftCenter);
	rightRect.moveCenter(rightCenter);
	this->_parameterControlWidget->move(rightRect.topLeft());
	this->move(leftRect.topLeft());
}
