#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_getButt_clicked();

    void on_pushButtAnalize_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

    void on_cancelButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
