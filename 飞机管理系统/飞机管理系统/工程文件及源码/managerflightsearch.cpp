#include "managerflightsearch.h"
#include "ui_managerflightsearch.h"

ManagerFlightSearch::ManagerFlightSearch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagerFlightSearch)
{
    ui->setupUi(this);
}

ManagerFlightSearch::~ManagerFlightSearch()
{
    delete ui;
}
