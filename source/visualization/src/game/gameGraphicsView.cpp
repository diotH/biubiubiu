#include "game/gameGraphicsView.h"
#include "game/planeBase.h"

CGameGraphicsView::CGameGraphicsView(QWidget *parent)
    :QGraphicsView (parent)
{
    //将背景变为透明
    setStyleSheet("background: transparent;");
    //关闭滚动条
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    m_myPlane = new CPlaneBase();
    QGraphicsScene *scene = new QGraphicsScene();
    this->setScene(scene);
    scene->setSceneRect(0,0,680,800);

    scene->addItem(m_myPlane);

    m_myPlane->setPos(300,600);
}

CGameGraphicsView::~CGameGraphicsView()
{

}
