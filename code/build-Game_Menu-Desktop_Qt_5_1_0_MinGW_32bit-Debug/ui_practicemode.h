/********************************************************************************
** Form generated from reading UI file 'practicemode.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRACTICEMODE_H
#define UI_PRACTICEMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PracticeMode
{
public:
    QGraphicsView *graphicsView;
    QPushButton *pushButton;

    void setupUi(QDialog *PracticeMode)
    {
        if (PracticeMode->objectName().isEmpty())
            PracticeMode->setObjectName(QStringLiteral("PracticeMode"));
        PracticeMode->resize(1350, 690);
        graphicsView = new QGraphicsView(PracticeMode);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1350, 690));
        graphicsView->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Quad_bike_desktop-wallpaper_4.jpg);"));
        pushButton = new QPushButton(PracticeMode);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1180, 620, 150, 50));
        pushButton->setStyleSheet(QLatin1String("font: 75 16pt \"Comic Sans MS\";\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(52, 137, 223, 255), stop:1 rgba(255, 255, 255, 255));"));

        retranslateUi(PracticeMode);

        QMetaObject::connectSlotsByName(PracticeMode);
    } // setupUi

    void retranslateUi(QDialog *PracticeMode)
    {
        PracticeMode->setWindowTitle(QApplication::translate("PracticeMode", "Dialog", 0));
        pushButton->setText(QApplication::translate("PracticeMode", "Main Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class PracticeMode: public Ui_PracticeMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRACTICEMODE_H
