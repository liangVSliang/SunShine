#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

void MainWindow::openTable()
{
    //创建模型，打开数据库表格
    tabModel=new QSqlTableModel(this,DB);
    tabModel->setTable("employee");
    tabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    tabModel->setSort(tabModel->fieldIndex("empNo"),Qt::AscendingOrder);
    if(!(tabModel->select()))
    {
        QMessageBox::critical(this,"错误","数据库表格打开失败:"+tabModel->lastError().text());
    }
    ui->statusbar->showMessage(QString("记录条数为：%1").arg(tabModel->rowCount()));
    //设置字段显示标题
    tabModel->setHeaderData(tabModel->fieldIndex("empNo"),Qt::Horizontal,"学号");
    tabModel->setHeaderData(tabModel->fieldIndex("Name"),Qt::Horizontal,"姓名");
    tabModel->setHeaderData(tabModel->fieldIndex("Gender"),Qt::Horizontal,"性别");
    tabModel->setHeaderData(tabModel->fieldIndex("Birthday"),Qt::Horizontal,"出生日期");
    tabModel->setHeaderData(tabModel->fieldIndex("Province"),Qt::Horizontal,"省份");
    tabModel->setHeaderData(tabModel->fieldIndex("Department"),Qt::Horizontal,"班级");
    tabModel->setHeaderData(tabModel->fieldIndex("Salary"),Qt::Horizontal,"成绩");
    tabModel->setHeaderData(tabModel->fieldIndex("Memo"),Qt::Horizontal,"备注");
    selModel=new QItemSelectionModel(tabModel,this);

    ui->tableView->setModel(tabModel);
    ui->tableView->setSelectionModel(selModel);
    //ui->tableView->setColumnHidden(tabModel->fieldIndex("Memo"),true);
    ui->tableView->setColumnHidden(tabModel->fieldIndex("Photo"),true);

    //代理
    QStringList strList;
    strList<<"男"<<"女";
    delegateSex.setItems(strList,false);
    ui->tableView->setItemDelegateForColumn(tabModel->fieldIndex("Gender"),&delegateSex);
    strList.clear();

    strList<<"恐龙班"<<"野猪班"<<"大象班";
    delegateDepart.setItems(strList,false);
    ui->tableView->setItemDelegateForColumn(tabModel->fieldIndex("Department"),&delegateDepart);

    //字段与widget映射
    dataMapper=new QDataWidgetMapper(this);
    dataMapper->setModel(tabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
    dataMapper->addMapping(ui->dbSpinEmpNo,tabModel->fieldIndex("empNo"));
    dataMapper->addMapping(ui->dbEditName,tabModel->fieldIndex("Name"));
    dataMapper->addMapping(ui->dbComboSex,tabModel->fieldIndex("Gender"));
    dataMapper->addMapping(ui->dbEditBirth,tabModel->fieldIndex("Birthday"));
    dataMapper->addMapping(ui->dbComboProvince,tabModel->fieldIndex("Province"));
    dataMapper->addMapping(ui->dbComboDep,tabModel->fieldIndex("Department"));
    dataMapper->addMapping(ui->dbSpinSalary,tabModel->fieldIndex("Salary"));
    dataMapper->addMapping(ui->dbEditMemo,tabModel->fieldIndex("Memo"));
    dataMapper->toFirst();

    //获取字段名更新combox
    //QSqlRecord emptyRec=tabModel->record();
    // for(int i=0;i<emptyRec.count();++i)
    // {
    //     ui->comboFields->addItem(emptyRec.fieldName(i));
    // }
    connect(selModel,&QItemSelectionModel::currentRowChanged,this,&MainWindow::do_currentRowChanged);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 设置背景图片为bj.jpg
    this->setObjectName("mainWindow");
    this->setStyleSheet("#mainWindow{border-image:url(:/new/prefix2/img/background.jpg);}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actOpenDB_triggered()
{
    // QString aFile=QFileDialog::getOpenFileName(this,"选择文件","","SQLite数据库(*.db3)");
    // if(aFile.isEmpty())
    //     return;
    DB=QSqlDatabase::addDatabase("QSQLITE");//添加驱动
    DB.setDatabaseName("demodb.db3");
    if(!DB.open())
        QMessageBox::warning(this,"错误","数据库打开失败");
    else
        openTable();
}



void MainWindow::do_currentRowChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(previous);
    if(!current.isValid())
    {
        ui->dbLabPhoto->clear();
    }
    dataMapper->setCurrentIndex(current.row());
    QSqlRecord curRec=tabModel->record(current.row());
    if(curRec.isNull("Photo")){
        ui->dbLabPhoto->clear();
    }else{
        QPixmap pic;
        pic.loadFromData(curRec.value("Photo").toByteArray());
        ui->dbLabPhoto->setPixmap(pic.scaledToWidth(ui->dbLabPhoto->size().width()));
    }
}


void MainWindow::on_actAdd_triggered()
{
    QSqlRecord rec=tabModel->record();
    rec.setValue(tabModel->fieldIndex("Gender"),"女");
    tabModel->insertRecord(tabModel->rowCount(),rec);
    selModel->clearSelection();
    selModel->setCurrentIndex(tabModel->index(tabModel->rowCount()-1,1)
                              ,QItemSelectionModel::Select);
    ui->statusbar->showMessage(QString("记录条数为：%1").arg(tabModel->rowCount()));
}


void MainWindow::on_actInsert_triggered()
{
    QModelIndex curIndex=ui->tableView->currentIndex();
    QSqlRecord rec=tabModel->record();
    rec.setValue(tabModel->fieldIndex("Gender"),"女");
    tabModel->insertRecord(curIndex.row(),rec);
    selModel->clearSelection();
    selModel->setCurrentIndex(curIndex
                              ,QItemSelectionModel::Select);
    ui->statusbar->showMessage(QString("记录条数为：%1").arg(tabModel->rowCount()));
}


void MainWindow::on_actDelete_triggered()
{
    QModelIndex curIndex=ui->tableView->currentIndex();
    tabModel->removeRow(curIndex.row());
    ui->statusbar->showMessage(QString("记录条数为：%1").arg(tabModel->rowCount()));
}


void MainWindow::on_actPhoto_triggered()
{
    QString aFile=QFileDialog::getOpenFileName(this,"选择一个图片","","照片(*.jpg)");
    if(aFile.isEmpty())
        return;
    QFile *file=new QFile(aFile);
    if(file->open(QIODevice::ReadOnly))
    {
        QByteArray data=file->readAll();
        file->close();
        delete file;

        QSqlRecord curRec=tabModel->record(selModel->currentIndex().row());
        curRec.setValue("Photo",data);
        tabModel->setRecord(selModel->currentIndex().row(),curRec);

        QPixmap pix;
        pix.load(aFile);
        ui->dbLabPhoto->setPixmap(pix.scaledToWidth(ui->dbLabPhoto->width()));
    }
}


void MainWindow::on_actSave_triggered()
{
    bool res=tabModel->submitAll();
    if(!res)
        QMessageBox::information(this,"消息","数据库保存失败\n"+tabModel->lastError().text());
    ui->statusbar->showMessage(QString("记录条数为：%1").arg(tabModel->rowCount()));
}


void MainWindow::on_pushButton_clicked()
{
    QString na=ui->findName->text();
    //tabModel->setFilter("Name="+na);
    tabModel->setFilter(QObject::tr("Name='%1'").arg(na));
        ui->statusbar->showMessage(QString("记录条数为：%1").arg(tabModel->rowCount()));
}

