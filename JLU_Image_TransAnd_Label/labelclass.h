#ifndef LABELCLASS_H
#define LABELCLASS_H

#include<QString>
#include<Qlist>
#include<QPair>
#include<QPoint>
#include<QDebug>
typedef QString LabelName;
typedef unsigned int LabelIndex;
typedef QPair<LabelIndex,LabelName> LabelPair;
typedef QList<QPoint> CurPolyPoints;
typedef QList<CurPolyPoints> CurPixPicPolyPoints;

void qDebugTheLabelList(QList<LabelPair> listPair);
void qDebugTheLabelPair(LabelPair listPair);
#endif // LABELCLASS_H
