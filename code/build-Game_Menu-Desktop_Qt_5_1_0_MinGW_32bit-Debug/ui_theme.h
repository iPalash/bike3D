/********************************************************************************
** Form generated from reading UI file 'theme.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THEME_H
#define UI_THEME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Theme
{
public:
    QGraphicsView *graphicsView;
    QPushButton *pushButton;

    void setupUi(QDialog *Theme)
    {
        if (Theme->objectName().isEmpty())
            Theme->setObjectName(QStringLiteral("Theme"));
        Theme->resize(1350, 690);
        graphicsView = new QGraphicsView(Theme);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1350, 690));
        graphicsView->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/the-apocalypse.jpg);"));
        pushButton = new QPushButton(Theme);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1180, 620, 150, 50));
        pushButton->setStyleSheet(QLatin1String("font: 75 16pt \"Comic Sans MS\";\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(52, 137, 223, 255), stop:1 rgba(255, 255, 255, 255));"));

        retranslateUi(Theme);

        QMetaObject::connectSlotsByName(Theme);
    } // setupUi

    void retranslateUi(QDialog *Theme)
    {
        Theme->setWindowTitle(QApplication::translate("Theme", "Dialog", 0));
        pushButton->setText(QApplication::translate("Theme", "Main Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class Theme: public Ui_Theme {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEME_H
