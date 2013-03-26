#ifndef ALGORITHM_SYNCHRONIZEDCONDENSATION_H
#define ALGORITHM_SYNCHRONIZEDCONDENSATION_H

#include "FrameProcessor.h"
#include "CondensationParameters.h"
#include <QMutex>

template<typename T> class SynchronizedCondensation : public FrameProcessor{
private:
	T processor;
	CondensationParameters temp;
	QMutex lock;
	bool changed = false;

	void update(){
		lock.lock();
		if(changed){
			processor.parameters = temp;
			changed = false;
		}
		lock.unlock();
	}

public:
	SynchronizedCondensation():temp(processor.parameters){}
	void process(const cv::Mat &in, cv::Mat &out){
		update();
		processor.process(in,out);
	}


	void changeParameters(const CondensationParameters& parameters){
		lock.lock();
		temp = parameters;
		changed = true;
		lock.unlock();
	}

	CondensationParameters getActualParameters(){
		return this->processor.parameters;
	}


};

#endif // ALGORITHM_SYNCHRONIZEDCONDENSATION_H
