#include "mainform.h"
#include "ui_mainform.h"

#include "collapseview.h"

#include <QColorDialog>
#include <QDebug>

MainForm::MainForm(QWidget *parent) :
    MoveableFramelessWindow(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    ui->page_4->layout()->addWidget(new CollapseView());

    //关联切换皮肤颜色按钮事件


}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::doChangeColor()
{

    //获取皮肤颜色
    QColor color = QColorDialog::getColor(Qt::white, this);

    //转换颜色为字符串
    QString msg = QString("rgba(%1,%2,%3,%4)").arg(QString::number(color.red()), QString::number(color.green()), QString::number(color.blue()),QString::number(color.alpha()));

    //组合成qcc样式表
    QString style=QString("#%1{background-color:%2;}").arg(ui->centralwidget->objectName(),msg);

    //定义样式
    ui->centralwidget->setStyleSheet(style);

}

QWidget *MainForm::getDragnWidget()
{
    return ui->main_top;
}
