#ifndef HIGHSCORES_H
#define HIGHSCORES_H
#random
#include <QDialog>

namespace Ui {
class HighScores;
}

class HighScores : public QDialog
{
    Q_OBJECT
    
public:
    explicit HighScores(QWidget *parent = 0);
    ~HighScores();
    void readscore();
    
private slots:
    void on_pushButton_clicked();



private:
    Ui::HighScores *ui;
};

#endif // HIGHSCORES_H
