#include "practicemode.h"
#include "ui_practicemode.h"
#include "mainwindow.h"

PracticeMode::PracticeMode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PracticeMode)
{
    ui->setupUi(this);
}

PracticeMode::~PracticeMode()
{
    delete ui;
}

void PracticeMode::on_pushButton_clicked()
{
    MainWindow *mw=new MainWindow();
    mw->show();
    this->close();
}
