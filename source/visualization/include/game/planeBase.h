#ifndef  PLANEBASE_H
#define  PLANEBASE_H

#include "visualizationImprot.h"

class VISUALIZATION_EXPORT CPlaneBase : public QGraphicsItem
{
    //Q_OBJECT
public:
    CPlaneBase();
    ~CPlaneBase();

    QRectF boundingRect() const;
    void paint(QPainter *painter,const  QStyleOptionGraphicsItem *option,QWidget *widget);

    void setPlane(QPixmap plane, QSizeF planeSize);
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    QPixmap m_planePix;
    QRectF  m_planeSize;
    bool    m_planeIsSelected;

};

#endif
