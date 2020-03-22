#include "game/planeBase.h"

CPlaneBase::CPlaneBase()
    :m_planeSize(0,0,80,80),m_planeIsSelected(false)
{
    QPixmap pixmap("://Resource/plane/myPlane_1.png");
    m_planePix = pixmap;
}

CPlaneBase::~CPlaneBase()
{

}

QRectF CPlaneBase::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth/2, 0 - penWidth/2,
                  m_planeSize.width() + penWidth, m_planeSize.height() + penWidth);
}

void CPlaneBase::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    QRectF rectF(m_planePix.rect());
    painter->drawPixmap(m_planeSize,m_planePix,rectF);
}

void CPlaneBase::setPlane(QPixmap plane, QSizeF planeSize)
{
    m_planePix = plane;
    m_planeSize.setSize(planeSize);
    update();
}

void CPlaneBase::keyPressEvent(QKeyEvent *event)
{
    Q_UNUSED(event)
}

void CPlaneBase::keyReleaseEvent(QKeyEvent *event)
{
    Q_UNUSED(event)
}

void CPlaneBase::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_planeIsSelected = true;

    }
}

void CPlaneBase::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_planeIsSelected)
    {
        //鼠标移动到场景中的坐标
        QPointF movePos = event->pos();

        qreal xAddValue = movePos.x() - m_planeSize.width()/2;
        qreal yAddValue = movePos.y() - m_planeSize.height()/2;
        setPos(mapToScene(xAddValue,yAddValue));

    }
}

void CPlaneBase::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_planeIsSelected = false;
    }
}
