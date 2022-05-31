#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <QWidget>
#include<QSqlDatabase>
#include<QtSql>
#include<QDebug>
#include<QMessageBox>

namespace Ui {
class CheckBox;
}

class CheckBox : public QWidget
{
    Q_OBJECT

public:
    explicit CheckBox(QWidget *parent = nullptr);
    ~CheckBox();
    bool type;

private slots:
    void on_returnButton_clicked();

    void on_admitButton_clicked();

private:
    Ui::CheckBox *ui;

signals:
    void successUser(QString id,QString name);
    void successManager(QString id,QString company);
};

#endif // CHECKBOX_H
