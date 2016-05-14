/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

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

class Ui_Dialog
{
public:
    QPushButton *pushButton_retry;
    QPushButton *pushButton_exit;
    QLabel *label;
    QGraphicsView *graphicsView;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(500, 700);
        Dialog->setSizeGripEnabled(false);
        pushButton_retry = new QPushButton(Dialog);
        pushButton_retry->setObjectName(QStringLiteral("pushButton_retry"));
        pushButton_retry->setGeometry(QRect(0, 600, 250, 100));
        QFont font;
        font.setFamily(QStringLiteral("Smudger LET"));
        font.setPointSize(36);
        font.setBold(true);
        font.setWeight(75);
        pushButton_retry->setFont(font);
        pushButton_exit = new QPushButton(Dialog);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(250, 600, 250, 100));
        pushButton_exit->setFont(font);
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 500, 100));
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("background-color: rgb(188, 188, 188);"));
        label->setAlignment(Qt::AlignCenter);
        graphicsView = new QGraphicsView(Dialog);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 100, 500, 500));
        graphicsView->raise();
        pushButton_retry->raise();
        pushButton_exit->raise();
        label->raise();

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        pushButton_retry->setText(QApplication::translate("Dialog", "RETRY", 0));
        pushButton_exit->setText(QApplication::translate("Dialog", "EXIT", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
