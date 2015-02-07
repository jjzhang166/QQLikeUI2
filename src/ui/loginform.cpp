#include "loginform.h"
#include "ui_loginform.h"


#include <windows.h>

#include <QKeyEvent>
#include <QMouseEvent>
#include <QRect>
#include <QPoint>
#include <QGridLayout>

LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::mousePressEvent(QMouseEvent *event)
{
    //判断位置
    QRect rect=ui->login_top_widget->rect();
    QPoint pos=event->pos();
    bool shouldMove=pos.x()>=rect.left()&&pos.x()<=rect.right()&&pos.y()>=rect.top()&&pos.y()<=rect.bottom();
    if(shouldMove){
        if (ReleaseCapture()){
            SendMessage(HWND(this->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
        }
    }
    event->ignore();
}
