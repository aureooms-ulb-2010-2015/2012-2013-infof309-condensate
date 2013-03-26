#include "MainWindow.h"

#include <QApplication>

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
        }
        else{
                this->_parameterControlWidget->show();
        }
}
