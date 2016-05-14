#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGraphicsScene>
#include <QSound>
#include <QTime>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

signals:
    void retry();
    void quit();

private slots:
    void gameEnd(const int &);
    void on_pushButton_exit_clicked();
    void on_pushButton_retry_clicked();

private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;
    QSound *endSound;
};

#endif // DIALOG_H
