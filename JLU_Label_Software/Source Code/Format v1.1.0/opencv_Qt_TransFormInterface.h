#ifndef OPENCV_QT_TRANSFORMINTERFACE_H
#define OPENCV_QT_TRANSFORMINTERFACE_H
#include <opencv2/opencv.hpp>
#include <QPoint>
#include <QRect>
cv::Point QPointToCVPoint(QPoint point);
QPoint CVPointToQPoint(cv::Point point);
cv::Rect QRectToCVRect(QRect rect);
QRect CVRectToQRect(cv::Rect rect);

#endif // OPENCV_QT_TRANSFORMINTERFACE_H
