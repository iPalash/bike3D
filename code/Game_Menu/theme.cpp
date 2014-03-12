#include "theme.h"
#include "ui_theme.h"
#include "mainwindow.h"

Theme::Theme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Theme)
{
    ui->setupUi(this);
}

Theme::~Theme()
{
    delete ui;
}

void Theme::on_pushButton_clicked()
{
    MainWindow *mw=new MainWindow();
    mw->show();
    this->close();
}
