#include "game/gameGraphicsView.h"


CGameGraphicsView::CGameGraphicsView(QWidget *parent)
    :QGraphicsView (parent)
{
    //将背景变为透明
    setStyleSheet("background: transparent;");

//    QLabel *label = new QLabel(this);
//    label->setStyleSheet("background:red;");
//    label->setGeometry(10,10,100,100);
}

CGameGraphicsView::~CGameGraphicsView()
{

}
