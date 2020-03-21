#include "game/gameBackground.h"
#include "game/gameGraphicsView.h"
//#include <QPropertyAnimation>

CGameBackground::CGameBackground(QWidget *parent)
    :QWidget (parent)
{
    resize(680,800);
    createUI();

    QLabel *background_1 = new QLabel(this);
    background_1->setFixedSize(680,596);
    background_1->setPixmap(QPixmap("://Resource/map/forest-01.jpg"));
    QLabel *background_2 = new QLabel(this);
    background_2->setFixedSize(680,520);
    background_2->setPixmap(QPixmap("://Resource/map/forest-02.jpg"));
    QLabel *background_3 = new QLabel(this);
    background_3->setFixedSize(680,597);
    background_3->setPixmap(QPixmap("://Resource/map/forest-03.jpg"));

    QPropertyAnimation *animation_1 = new QPropertyAnimation(background_1,"geometry",this);
    animation_1->setDuration(5000);
    animation_1->setKeyValueAt(0,QRect(0,204,680,596));
    animation_1->setKeyValueAt(1,QRect(0,800,680,596));

    QPropertyAnimation *animation_2 = new QPropertyAnimation(background_2,"geometry",this);
    animation_2->setDuration(5000);
    animation_2->setKeyValueAt(0,QRect(0,-316,680,596));
    animation_2->setKeyValueAt(1,QRect(0,280,680,596));

    QPropertyAnimation *animation_3 = new QPropertyAnimation(background_3,"geometry",this);
    animation_3->setDuration(5000);
    animation_3->setKeyValueAt(0,QRect(0,-913,680,596));
    animation_3->setKeyValueAt(1,QRect(0,-316,680,596));

//    connect(animation_1,SIGNAL(stateChanged(QAbstractAnimation::State,QAbstractAnimation::State)),
//            this,SLOT(stateChanged(QAbstractAnimation::State,QAbstractAnimation::State)));
    QParallelAnimationGroup *group = new QParallelAnimationGroup(this);
    group->addAnimation(animation_1);
    group->addAnimation(animation_2);
    group->addAnimation(animation_3);
    group->start();
    group->setLoopCount(-1);

    m_gameGraphicsView->raise();
}

CGameBackground::~CGameBackground()
{

}

void CGameBackground::stateChanged(QAbstractAnimation::State newState, QAbstractAnimation::State oldState)
{
    qDebug()<<"new state"<<newState<<"old state"<<oldState;
}

void CGameBackground::createUI()
{
    m_gameGraphicsView = new CGameGraphicsView(this);
    QHBoxLayout *layout = new QHBoxLayout();
    layout->setMargin(0);
    layout->setSpacing(0);
    this->setLayout(layout);
    layout->addWidget(m_gameGraphicsView);
}

