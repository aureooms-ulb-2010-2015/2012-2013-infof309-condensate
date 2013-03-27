#ifndef SEGMENTATIONTAB_H
#define SEGMENTATIONTAB_H

#include <QWidget>
#include "CustomDial.h"
#include "CondensationParameters.h"

class SegmentationTab : public QWidget{
	Q_OBJECT
private:
    CustomDial* _minWidth = new CustomDial("Min width", 1, 640);
    CustomDial* _maxWidth = new CustomDial("Max width", 1, 640);
	CustomDial* _minHeight = new CustomDial("Min height", 1, 640);
	CustomDial* _maxHeight = new CustomDial("Max height", 1, 640);
	CustomDial* _min_acc_iterations = new CustomDial("Min accumulator iterations", 0, 1000);
public:
	explicit SegmentationTab(QWidget *parent = 0);
	void loadParameters(const CondensationParameters& parameters);
	
signals:
	void minWidthChanged(int);
	void maxWidthChanged(int);
	void minHeightChanged(int);
	void maxHeightChanged(int);
	void minAccumulatorIterationsChanged(int);
	
public slots:
	
};

#endif // SEGMENTATIONTAB_H
