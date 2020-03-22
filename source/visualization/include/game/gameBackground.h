#ifndef GAMEBACKGROUND_H
#define GAMEBACKGROUND_H

#include "visualizationImprot.h"

class CGameGraphicsView;

class VISUALIZATION_EXPORT CGameBackground : public QWidget
{
    Q_OBJECT
public:
    CGameBackground(QWidget *parent = nullptr);
    ~CGameBackground();
public slots:
    void stateChanged(QAbstractAnimation::State newState, QAbstractAnimation::State oldState);
    void timeoutSLot();
protected:
private:
    //创建界面
    void createUI();
private:

    CGameGraphicsView *m_gameGraphicsView;
    QPropertyAnimation *animation_1;
    QPropertyAnimation *animation_2;
    QPropertyAnimation *animation_3;
    QParallelAnimationGroup *group;

};

#endif
