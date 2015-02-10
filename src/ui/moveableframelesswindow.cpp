#include "moveableframelesswindow.h"


#include <windows.h>

#include <QKeyEvent>
#include <QMouseEvent>
#include <QRect>
#include <QPoint>
#include <QGridLayout>


MoveableFramelessWindow::MoveableFramelessWindow(QWidget *parent) :
    QWidget(parent)
{
    //设置窗体为无边框
    this->setWindowFlags(Qt::FramelessWindowHint);

    //设置底层背景透明
    setAttribute(Qt::WA_TranslucentBackground);

}

void MoveableFramelessWindow::mousePressEvent(QMouseEvent *event)
{

    //判断位置

    bool shouldMove=isPointInDragnWidget(getDragnWidget(),event->pos());

    if(shouldMove){
        if (ReleaseCapture()){
            SendMessage(HWND(this->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
        }
    }

    event->ignore();

}

bool MoveableFramelessWindow::isPointInDragnWidget(const QWidget *widget, const QPoint &point)
{
    //判断位置
    QRect rect=widget->rect();

    bool isIn=point.x()>=rect.left()&&point.x()<=rect.right()&&point.y()>=rect.top()&&point.y()<=rect.bottom();

    return isIn;
}
