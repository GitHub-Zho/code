#ifndef MANAGERFLIGHTSEARCH_H
#define MANAGERFLIGHTSEARCH_H

#include <QWidget>

namespace Ui {
class ManagerFlightSearch;
}

class ManagerFlightSearch : public QWidget
{
    Q_OBJECT

public:
    explicit ManagerFlightSearch(QWidget *parent = nullptr);
    ~ManagerFlightSearch();

private:
    Ui::ManagerFlightSearch *ui;
};

#endif // MANAGERFLIGHTSEARCH_H
