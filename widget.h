#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtGui>
#include <QtCore>

namespace Ui {
class Widget;
}



class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public:
    Ui::Widget *ui;

protected:

    void paintEvent(QPaintEvent *event); // This is re-implemented from QWidget
protected slots:
      void draw();
   private:
      bool pressed;
};

#endif // WIDGET_H
