#define _USE_MATH_DEFINES
#include "widget.h"
#include "ui_widget.h"
#include <cmath>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked(bool)),this,SLOT(draw()));
}

Widget::~Widget()
{
    delete ui;
}



void Widget::paintEvent(QPaintEvent *e)
{

    QPainter painter(this);
    if(pressed)
          {
        float x = 0;
        float y = 0;
        float angle = 0.0f;
        float x1 = 0;
        float y1 = 0;
        float turns = ui->lineEdit_4->text().toFloat()* 2 * M_PI;
        float xInput = ui->lineEdit->text().toFloat();
        float yInput = ui->lineEdit_2->text().toFloat();
        float step = ui->lineEdit_3->text().toFloat()/2*M_PI;
        for (float i = 0; i < turns; i+=0.02)
            {
            angle = 0.1 * i;
            x = (step * angle) * cos(i);
            y = (step * angle) * sin(i);
            painter.drawLine(yInput + y,xInput + x, yInput + y1,xInput + x1);
            x1 = x;
            y1 = y;
            }
          }
    QWidget::paintEvent(e);

}

void Widget::draw()
   {
      pressed = true;
      update();
   }
