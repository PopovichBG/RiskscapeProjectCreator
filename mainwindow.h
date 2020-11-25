#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QDir>
#include <QDesktopServices>
#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_toolButton_clicked();

    void on_button_getJava_clicked();

    void on_button_getPython_clicked();

    void on_button_getQGIS_clicked();

    void on_button_getNotepad_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
