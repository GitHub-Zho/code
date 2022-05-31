#ifndef PAY_H
#define PAY_H

#include <QWidget>
#include <QDesktopWidget>

namespace Ui {
class Pay;
}

class Pay : public QWidget
{
    Q_OBJECT

public:
    explicit Pay(QWidget *parent = nullptr);
    ~Pay();


private slots:
    void on_payReturn_clicked();

    void on_pay_clicked();

    void on_cancle_clicked();

private:
    Ui::Pay *ui;

signals:
    void payClose();
    void payFinish();
    void payCancle();
};

#endif // PAY_H
