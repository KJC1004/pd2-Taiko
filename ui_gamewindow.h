/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QLabel *label_time;
    QLabel *label_score;
    QLabel *label_combo;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QMainWindow *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QStringLiteral("GameWindow"));
        GameWindow->resize(1200, 900);
        centralwidget = new QWidget(GameWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1200, 900));
        QFont font;
        font.setFamily(QStringLiteral("Smudger LET"));
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        graphicsView->setFont(font);
        label_time = new QLabel(centralwidget);
        label_time->setObjectName(QStringLiteral("label_time"));
        label_time->setGeometry(QRect(100, 30, 500, 100));
        QFont font1;
        font1.setFamily(QStringLiteral("Smudger LET"));
        font1.setPointSize(48);
        font1.setBold(true);
        font1.setWeight(75);
        label_time->setFont(font1);
        label_time->setStyleSheet(QStringLiteral(""));
        label_time->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_score = new QLabel(centralwidget);
        label_score->setObjectName(QStringLiteral("label_score"));
        label_score->setGeometry(QRect(700, 30, 500, 100));
        label_score->setFont(font1);
        label_score->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_combo = new QLabel(centralwidget);
        label_combo->setObjectName(QStringLiteral("label_combo"));
        label_combo->setGeometry(QRect(50, 400, 400, 100));
        QFont font2;
        font2.setFamily(QStringLiteral("Smudger LET"));
        font2.setPointSize(36);
        font2.setBold(true);
        font2.setWeight(75);
        label_combo->setFont(font2);
        label_combo->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_combo->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 700, 100, 100));
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(460, 700, 100, 100));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(740, 700, 100, 100));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(1020, 700, 100, 100));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);
        GameWindow->setCentralWidget(centralwidget);

        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GameWindow)
    {
        GameWindow->setWindowTitle(QApplication::translate("GameWindow", "MainWindow", 0));
        label_time->setText(QString());
        label_score->setText(QString());
        label_combo->setText(QString());
        label->setText(QApplication::translate("GameWindow", "S", 0));
        label_2->setText(QApplication::translate("GameWindow", "K", 0));
        label_3->setText(QApplication::translate("GameWindow", "A", 0));
        label_4->setText(QApplication::translate("GameWindow", "L", 0));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
