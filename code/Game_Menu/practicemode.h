#ifndef PRACTICEMODE_H
#define PRACTICEMODE_H

#include <QDialog>

namespace Ui {
class PracticeMode;
}

class PracticeMode : public QDialog
{
    Q_OBJECT
    
public:
    explicit PracticeMode(QWidget *parent = 0);
    ~PracticeMode();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::PracticeMode *ui;
};

#endif // PRACTICEMODE_H
