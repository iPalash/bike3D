/********************************************************************************
** Form generated from reading UI file 'highscores.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HIGHSCORES_H
#define UI_HIGHSCORES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_HighScores
{
public:
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;

    void setupUi(QDialog *HighScores)
    {
        if (HighScores->objectName().isEmpty())
            HighScores->setObjectName(QStringLiteral("HighScores"));
        HighScores->resize(1350, 690);
        graphicsView = new QGraphicsView(HighScores);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 10, 1350, 690));
        graphicsView->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Quad_bike_desktop-wallpaper_4.jpg);"));
        pushButton = new QPushButton(HighScores);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1180, 620, 150, 50));
        pushButton->setStyleSheet(QLatin1String("font: 75 16pt \"Comic Sans MS\";\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(52, 137, 223, 255), stop:1 rgba(255, 255, 255, 255));"));
        label = new QLabel(HighScores);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 40, 46, 13));
        label_2 = new QLabel(HighScores);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(220, 100, 46, 13));
        label_3 = new QLabel(HighScores);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(220, 140, 46, 13));
        label_4 = new QLabel(HighScores);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(220, 160, 46, 13));
        label_5 = new QLabel(HighScores);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(220, 190, 46, 13));
        label_6 = new QLabel(HighScores);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(220, 220, 46, 13));
        label_7 = new QLabel(HighScores);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(230, 250, 46, 13));
        label_8 = new QLabel(HighScores);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(230, 280, 46, 13));
        label_9 = new QLabel(HighScores);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(210, 320, 46, 13));
        label_10 = new QLabel(HighScores);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(190, 370, 46, 13));

        retranslateUi(HighScores);

        QMetaObject::connectSlotsByName(HighScores);
    } // setupUi

    void retranslateUi(QDialog *HighScores)
    {
        HighScores->setWindowTitle(QApplication::translate("HighScores", "Dialog", 0));
        pushButton->setText(QApplication::translate("HighScores", "Main Menu", 0));
        label->setText(QApplication::translate("HighScores", "TextLabel", 0));
        label_2->setText(QApplication::translate("HighScores", "TextLabel", 0));
        label_3->setText(QApplication::translate("HighScores", "TextLabel", 0));
        label_4->setText(QApplication::translate("HighScores", "TextLabel", 0));
        label_5->setText(QApplication::translate("HighScores", "TextLabel", 0));
        label_6->setText(QApplication::translate("HighScores", "TextLabel", 0));
        label_7->setText(QApplication::translate("HighScores", "TextLabel", 0));
        label_8->setText(QApplication::translate("HighScores", "TextLabel", 0));
        label_9->setText(QApplication::translate("HighScores", "TextLabel", 0));
        label_10->setText(QApplication::translate("HighScores", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class HighScores: public Ui_HighScores {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIGHSCORES_H
