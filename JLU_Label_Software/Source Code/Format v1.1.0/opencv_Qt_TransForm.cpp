#include "opencv_Qt_TransFormInterface.h"

/* global function defines here */
cv::Point QPointToCVPoint(QPoint point)
{
    return cv::Point(point.x(),point.y());
}
QPoint CVPointToQPoint(cv::Point point)
{
    return QPoint(point.x,point.y);
}
cv::Rect QRectToCVRect(QRect rect)
{
    return cv::Rect(
        QPointToCVPoint(rect.topLeft()),
        QPointToCVPoint(rect.bottomRight())
        );
}
QRect CVRectToQRect(cv::Rect rect)
{
    return QRect(
        CVPointToQPoint(rect.tl()),
        CVPointToQPoint(rect.br())
        );
}
