#ifndef MOVEABLEFRAMELESSWINDOW_H
#define MOVEABLEFRAMELESSWINDOW_H

#include <QObject>
#include <QWidget>
/**
 * @brief 无边框窗体
 */
class MoveableFramelessWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MoveableFramelessWindow(QWidget *parent);

protected:
    /**
     * @brief 鼠标拖动窗体
     * @param event
     */
    void mousePressEvent(QMouseEvent *event);


    /**
     * @brief 获取可拖动控件，必须由子类指定
     * @return
     */
    virtual QWidget*getDragnWidget()=0;

    /**
     * @brief 判断鼠标点击的位置是否进入可拖动区域
     * @param widget 可拖动控件位置
     * @param point  鼠标点击位置
     * @return
     */
     bool isPointInDragnWidget(const QWidget*widget,const QPoint &point);

signals:

public slots:

};

#endif // MOVEABLEFRAMELESSWINDOW_H
