#include "widget.h"
#include "ui_widget.h"

int coffee_price = 1000;
int juice_price = 1500;
int tea_price = 800;

int money = 0;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    set_button_enabled();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::set_button_disable(){
    ui->pushButton_juice->setEnabled(false);
    ui->pushButton_coffee->setEnabled(false);
    ui->pushButton_tea->setEnabled(false);

}

void Widget::set_button_enabled(){
    set_button_disable();
    if (juice_price <= money) ui->pushButton_juice->setEnabled(true);
    if (coffee_price <= money) ui->pushButton_coffee->setEnabled(true);
    if (tea_price <= money) ui->pushButton_tea->setEnabled(true);
}

void Widget::change_money(int money_){
    money += money_;
    ui->lcdNumber->display(money);
    set_button_disable();
    set_button_enabled();
}

void Widget::on_pushButton_500_clicked()
{
    change_money(500);
}


void Widget::on_pushButton_100_clicked()
{
    change_money(100);
}


void Widget::on_pushButton_50_clicked()
{
    change_money(50);
}


void Widget::on_pushButton_10_clicked()
{
    change_money(10);
}


void Widget::on_pushButton_coffee_clicked()
{
    change_money(-coffee_price);
}


void Widget::on_pushButton_juice_clicked()
{
    change_money(-juice_price);
}


void Widget::on_pushButton_tea_clicked()
{
    change_money(-tea_price);
}


void Widget::on_pushButton_reset_clicked()
{
    QMessageBox msg;
    int tmp = money;
    int five_hund_won_cnt = tmp / 500;
    tmp = tmp % 500;
    int one_hund_won_cnt = tmp / 100;
    tmp = tmp % 100;
    int fifty_won_cnt = tmp / 50;
    tmp = tmp % 50;
    int ten_won_cnt = tmp / 10;

    char str[300];
    sprintf(str, "[remainings]\n500: %d\n100: %d \n50:%d \n10: %d", five_hund_won_cnt, one_hund_won_cnt, fifty_won_cnt, ten_won_cnt);

    msg.information(nullptr, "remainings", str);

    change_money(-money);
}

