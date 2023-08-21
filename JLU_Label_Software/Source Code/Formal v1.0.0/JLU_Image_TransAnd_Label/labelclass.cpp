<<<<<<< HEAD
#include "labelclass.h"

void qDebugTheLabelList(QList<LabelPair> listPair)
{
    if(listPair.isEmpty()){
        qDebug() << "LabelList is NULL";
        return;
    }
    for(int i = 0; i < listPair.size();i++)
    {
        qDebug() << "标签号" <<  listPair[i].first << " 标签名称: " << listPair[i].second;
    }
}

void qDebugTheLabelPair(LabelPair pair)
{
    if(pair.second.isEmpty()){
        qDebug() <<"LabelPair is NULL";
        return;
    }
    qDebug() << "标签号" <<  pair.first << " 标签名称: " << pair.second;
}
=======
#include "labelclass.h"

void qDebugTheLabelList(QList<LabelPair> listPair)
{
    if(listPair.isEmpty()){
        qDebug() << "LabelList is NULL";
        return;
    }
    for(int i = 0; i < listPair.size();i++)
    {
        qDebug() << "标签号" <<  listPair[i].first << " 标签名称: " << listPair[i].second;
    }
}

void qDebugTheLabelPair(LabelPair pair)
{
    if(pair.second.isEmpty()){
        qDebug() <<"LabelPair is NULL";
        return;
    }
    qDebug() << "标签号" <<  pair.first << " 标签名称: " << pair.second;
}
>>>>>>> 5b85c2e78731c3e34a4c5d175edd7a5553af08ad
