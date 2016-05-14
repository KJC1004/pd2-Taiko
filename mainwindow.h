#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QSound>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *);

signals:
    void gwshow();
    void quit();

private slots:
    void on_pushButton_start_clicked();
    void on_pushButton_exit_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QSound *bgm;
};

#endif // MAINWINDOW_H
