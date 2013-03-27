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

	CondensationParameters getActualParameters(){
		return this->processor.parameters;
	}

	void spreadRangeChanged(int value){
		lock.lock();
		temp.spreadRange = value;
		changed = true;
		lock.unlock();
	}

	void maxCornersChanged(int value){
		lock.lock();
		temp.maxCorners = value;
		changed = true;
		lock.unlock();
	}
	void qualityLevelChanged(float value){
		lock.lock();
		temp.qualityLevel = value;
		changed = true;
		lock.unlock();
	}
	void minDistanceChanged(int value){
		lock.lock();
		temp.minDistance = value;
		changed = true;
		lock.unlock();
	}
	void blockSizeChanged(int value){
		lock.lock();
		temp.blockSize = value;
		changed = true;
		lock.unlock();
	}
	void kChanged(float value){
		lock.lock();
		temp.k = value;
		changed = true;
		lock.unlock();
	}
	void useHarrisDetectorChanged(bool value){
		lock.lock();
		temp.useHarrisDetector = value;
		changed = true;
		lock.unlock();
	}
	void matcherTypeChanged(const std::shared_ptr<DistanceMatcher>& matcher){
		lock.lock();
		temp.matcher = matcher;
		temp.matcher->setRadius(temp.R);
		changed = true;
		lock.unlock();
	}
	void maxDistChanged(int value){
		lock.lock();
		temp.MAX_DIST = value;
		changed = true;
		lock.unlock();
	}
	void radiusChanged(int value){
		lock.lock();
		temp.R = value;
		temp.matcher->setRadius(value);
		changed = true;
		lock.unlock();
	}
	void pollingRangeChanged(int value){
		lock.lock();
		temp.pollingRange = value;
		changed = true;
		lock.unlock();
	}
	void generatingRangeChanged(int value){
		lock.lock();
		temp.generatingRange = value;
		changed = true;
		lock.unlock();
	}
	void minWidthChanged(int value){
		lock.lock();
		temp.TARGET_MIN_WIDTH = value;
		changed = true;
		lock.unlock();
	}
	void maxWidthChanged(int value){
		lock.lock();
		temp.TARGET_MAX_WIDTH = value;
		changed = true;
		lock.unlock();
	}
	void minHeightChanged(int value){
		lock.lock();
		temp.TARGET_MIN_HEIGHT = value;
		changed = true;
		lock.unlock();
	}
	void maxHeightChanged(int value){
		lock.lock();
		temp.TARGET_MAX_HEIGHT = value;
		changed = true;
		lock.unlock();
	}
	void minAccumulatorIterationsChanged(int value){
		lock.lock();
		temp.MIN_ACCUMULATOR_ITERATIONS = value;
		changed = true;
		lock.unlock();
	}


};

#endif // ALGORITHM_SYNCHRONIZEDCONDENSATION_H
