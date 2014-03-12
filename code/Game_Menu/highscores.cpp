#include "highscores.h"
#include "ui_highscores.h"
#include "mainwindow.h"
#include <QStandardItemModel>
#include <QStandardItem>
#include "../finals/io/highscore.h"
#include <fstream>
#include <QAbstractItemModel>

HighScores::HighScores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HighScores)
{
    ui->setupUi(this);

}

void HighScores::readscore(){

    char s[20];
        ifstream f;
        f.open("../finals/dataFiles/highscore/0.txt");
       f>>s;
       f.close();
       ui->label->setText(s);
         f.open("../finals/dataFiles/highscore/1.txt");
        f>>s;
        f.close();
        ui->label_2->setText(s);

        f.open("../finals/dataFiles/highscore/2.txt");
       f>>s;
       f.close();
       ui->label_3->setText(s);
       f.open("../finals/dataFiles/highscore/3.txt");
      f>>s;
      f.close();
      ui->label_4->setText(s);
      f.open("../finals/dataFiles/highscore/4.txt");
     f>>s;
     f.close();
     ui->label_5->setText(s);
     f.open("../finals/dataFiles/highscore/5.txt");
    f>>s;
    f.close();
    ui->label_6->setText(s);
    f.open("../finals/dataFiles/highscore/6.txt");
   f>>s;
   f.close();
   ui->label_7->setText(s);
   f.open("../finals/dataFiles/highscore/7.txt");
  f>>s;
  f.close();
  ui->label_8->setText(s);
  f.open("../finals/dataFiles/highscore/8.txt");
 f>>s;
 f.close();
 ui->label_9->setText(s);
 f.open("../finals/dataFiles/highscore/9.txt");
f>>s;
f.close();
ui->label_10->setText(s);


}

HighScores::~HighScores()
{
    delete ui;
}

void HighScores::on_pushButton_clicked()
{
    MainWindow *mw=new MainWindow();
    mw->show();
    this->close();
}

