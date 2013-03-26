#ifndef SEGMENTATIONTAB_H
#define SEGMENTATIONTAB_H

#include <QWidget>
#include "CustomDial.h"

class SegmentationTab : public QWidget
{
	Q_OBJECT
private:
    CustomDial* _minWidth = new CustomDial("Min width", 1, 640);
    CustomDial* _maxWidth = new CustomDial("Max width", 1, 640);
    CustomDial* _minHeight = new CustomDial("Min height", 1, 640);
    CustomDial* _maxHeight = new CustomDial("Max height", 1, 640);
public:
	explicit SegmentationTab(QWidget *parent = 0);
	
signals:
	
public slots:
	
};

#endif // SEGMENTATIONTAB_H
