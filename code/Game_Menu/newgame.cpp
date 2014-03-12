#include "newgame.h"
#include "ui_newgame.h"
#include "mainwindow.h"
#include <fstream>
#include <QProcess>
#include <QString>
using namespace std;

NewGame::NewGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGame)
{
    ui->setupUi(this);
}

NewGame::~NewGame()
{
    delete ui;
}

void NewGame::on_pushButton_clicked()
{
    MainWindow *mw=new MainWindow();
    mw->show();
    this->close();
}

void NewGame::on_pushButton_9_clicked()
{
    ofstream p;
    p.open("../finals/dataFiles/trackID.txt");
    p<<1<<" "<<1;
    p.close();
}

void NewGame::on_pushButton_2_clicked()
{
    ofstream p;
    p.open("../finals/dataFiles/trackID.txt");
    p<<2<<" "<<1;
    p.close();
}

void NewGame::on_pushButton_3_clicked()
{
    ofstream p;
    p.open("../finals/dataFiles/trackID.txt");
    p<<3<<" "<<1;
    p.close();
}

void NewGame::on_pushButton_7_clicked()
{
    ofstream p;
    p.open("../finals/dataFiles/trackID.txt");
    p<<4<<" "<<1;
    p.close();
}

void NewGame::on_pushButton_10_clicked()
{
    ofstream p;
    p.open("../finals/dataFiles/trackID.txt");
    p<<5<<" "<<1;
    p.close();
}

void NewGame::on_pushButton_4_clicked()
{
    ofstream p;
    p.open("../finals/dataFiles/trackID.txt");
    p<<6<<" "<<1;
    p.close();
}

void NewGame::on_pushButton_5_clicked()
{
    ofstream p;
    p.open("../finals/dataFiles/trackID.txt");
    p<<7<<" "<<1;
    p.close();
}

void NewGame::on_pushButton_8_clicked()
{
    ofstream p;
    p.open("../finals/dataFiles/trackID.txt");
    p<<8<<" "<<1;
    p.close();
}

void NewGame::on_pushButton_11_clicked()
{
    ofstream p;
    p.open("../finals/dataFiles/trackID.txt");
    p<<9<<" "<<1;
    p.close();
}

void NewGame::on_pushButton_6_clicked()
{
    ofstream p;
    p.open("../finals/dataFiles/trackID.txt");
    p<<0<<" "<<1;
    p.close();
}

void NewGame::on_pushButton_12_clicked()
{
    QProcess* process=new QProcess(this);
    QString path="..\\finals\\binary";
    process->setWorkingDirectory(path);
    QString temp="\""+path+"/render.exe"+"\"";
    process->start(temp);

}
