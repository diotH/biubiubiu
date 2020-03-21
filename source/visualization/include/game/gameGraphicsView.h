#ifndef GAMEGRAPHICSVIEW_H
#define GAMEGRAPHICSVIEW_H

#include "visualizationImprot.h"

class VISUALIZATION_EXPORT CGameGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    CGameGraphicsView(QWidget *parent = nullptr);
    ~CGameGraphicsView();


};

#endif
