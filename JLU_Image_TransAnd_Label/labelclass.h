#ifndef LABELCLASS_H
#define LABELCLASS_H

#include<QString>
#include<Qlist>
#include<QPair>
#include<QPoint>
typedef QString LabelName;
typedef unsigned int LabelIndex;
typedef QPair<LabelIndex,LabelName> LabelPair;
typedef QList<QPoint> CurPolyPoints;
typedef QList<CurPolyPoints> CurPixPicPolyPoints;
#endif // LABELCLASS_H
