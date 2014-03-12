#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newgame.h"
#include "practicemode.h"
#include "highscores.h"
#include "instructions.h"
#include "theme.h"
#include <fstream>
#include <QString>
#include <QProcess>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_4_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_clicked()
{
    NewGame *ng=new NewGame();
    ng->showFullScreen();
    this->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    ofstream p;
    p.open("../finals/dataFiles/trackID.txt");
    p<<3<<" "<<0;
    p.close();
    QProcess* process=new QProcess(this);
    QString path="..\\finals\\binary";
    process->setWorkingDirectory(path);
    QString temp="\""+path+"/render.exe"+"\"";
    process->start(temp);
}

void MainWindow::on_pushButton_3_clicked()
{
    HighScores *hs=new HighScores();
    hs->readscore();
    hs->showFullScreen();

    this->close();
}

void MainWindow::on_pushButton_5_clicked()
{
    Instructions *in=new Instructions();
    in->show();
    this->close();
}

void MainWindow::on_pushButton_6_clicked()
{
    Theme *th=new Theme();
    th->show();
    this->close();
}
