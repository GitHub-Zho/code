#include "firstwidget.h"
#include "ui_firstwidget.h"




FirstWidget::FirstWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FirstWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("飞机管理系统(firstwidget)");

    //界面初始化
    initialize();

    connect(&checkBox,&CheckBox::successManager,this,&FirstWidget::managerLogin);
    connect(&checkBox,&CheckBox::successUser,this,&FirstWidget::userLogin);
    connect(&managerpage,&ManagerPage::closeManagerPage,this,&FirstWidget::thisShow);
    connect(&userSearch,&UserSearch::userSearchClose,this,&FirstWidget::thisShow);
    connect(&database,&Database::getBase,this,&FirstWidget::databaseCheck);
}

FirstWidget::~FirstWidget()
{
    delete ui;
}


//界面初始化
void FirstWidget::initialize()
{
    this->resize( QSize( 1000, 800));

    //设置字体大小
    QFont ft;
    ft.setPointSize(20);
    ui->label->setFont(ft);
    ui->label->adjustSize();
    ui->userLogin->adjustSize();
    ui->managerLogin->adjustSize();
}


//显示该界面，居中
void FirstWidget::thisShow()
{
    this->show();
}

//检验是否连接成功
void FirstWidget::databaseCheck(QString Id,QString password,QString name)
{
    db = QSqlDatabase::database("mybase");

    //连接数据库
    db.setHostName("127.0.0.1");
    db.setDatabaseName(name);
    db.setUserName(Id);
    db.setPassword(password);

    //提示
    if(db.open())
    {
        dbConnect = true;
        QMessageBox::information(this,"infor","数据库连接成功");
    }
    else
    {
        QMessageBox::information(this,"infor","数据库连接失败");
    }

}


//管理员登录
void FirstWidget::managerLogin(QString id,QString company)
{
    if (dbConnect == true)
    {
        this->hide();
        checkBox.hide();

        //传管理员相关信息
        managerpage.id = id;
        managerpage.company = company;
        managerpage.show();
    }
    else

        QMessageBox::information(this,"infor","请连接数据库");

}


//用户登录
void FirstWidget::userLogin(QString id)
{
    if (dbConnect == true)
    {
    this->hide();
    checkBox.hide();

    //传用户相关信息
    userSearch.id=id;
    userSearch.initialize();
    userSearch.show();
    }
    else

        QMessageBox::information(this,"infor","请连接数据库");
}


//管理员登录，弹出登录框
void FirstWidget::on_managerLogin_clicked()
{
    //告知登录为管理员
    checkBox.type=true;

    checkBox.show();
}

//用户登录，弹出登录框
void FirstWidget::on_userLogin_clicked()
{
    //告知登录为用户
    checkBox.type=false;

    checkBox.show();
}

void FirstWidget::on_database_clicked()
{
    database.show();
}
