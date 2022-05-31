#ifndef SEATTABLE_H
#define SEATTABLE_H

#include <QWidget>
#include<QSqlDatabase>
#include<QSqlRecord>
#include<QSqlQueryModel>
#include<QMessageBox>

namespace Ui {
class SeatTable;
}

class SeatTable : public QWidget
{
    Q_OBJECT

public:
    explicit SeatTable(QWidget *parent = nullptr);
    ~SeatTable();

    void initialize();

    QSqlDatabase db;
    QSqlQueryModel * qModel;
    QSqlRecord curRec;


    QString sql;
    QString seat;

private slots:

    void on_seatTableReturn_clicked();

    void on_seatTableChoose_clicked();

private:
    Ui::SeatTable *ui;

signals:
    void seatTableClose();
    void chooseSeat(QString seat);
};

#endif // SEATTABLE_H
