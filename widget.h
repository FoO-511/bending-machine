#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <stdlib.h>
#include <stdio.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_500_clicked();

    void on_pushButton_100_clicked();

    void on_pushButton_50_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_coffee_clicked();

    void on_pushButton_juice_clicked();

    void on_pushButton_tea_clicked();

    void on_pushButton_reset_clicked();

    void set_button_enabled();

    void set_button_disable();

    void change_money(int money_);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
