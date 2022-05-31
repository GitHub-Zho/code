#include "database.h"
#include "ui_database.h"

Database::Database(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Database)
{
    ui->setupUi(this);
}

Database::~Database()
{
    delete ui;
}

//关闭窗口
void Database::on_databaseReturn_clicked()
{
    this->hide();
}

void Database::on_databaseConnect_clicked()
{
    this->hide();
    emit getBase(ui->id->text(),ui->password->text(),ui->baseName->text());
}
