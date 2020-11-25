#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "riskscapeproject.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    RiskScapeProject newProject(ui->lineEdit->text(), ui->lineEdit_2->text());

    if (newProject.isValid()) {

        newProject.createDirectory("/Functions");
        newProject.createDirectory("/Types");
        newProject.createDirectory("/Output");
        newProject.createDirectory("/Data");
        newProject.createDirectory("/Data/Assets");
        newProject.createDirectory("/Data/Hazards");
        newProject.createDirectory("/Data/Aggregation");
        newProject.createDirectory("/Data/Resources");

        if(ui->checkBox->isChecked()) {

            newProject.createFile("types.ini", "/Types");
            newProject.createFile("bookmarks.ini", "");
            newProject.createFile("SampleFunction.py", "/Functions");
            newProject.createFile("project.ini", "");
            newProject.createFile("RiskScape_Model.bat", "");

        }

    }

    QApplication::quit();
}

void MainWindow::on_toolButton_clicked()
{
    QString homeDirectory = QFileDialog::getExistingDirectory(this, "Choose Directory", QDir::homePath());
    ui->lineEdit_2->setText(homeDirectory);
}

void MainWindow::on_button_getJava_clicked()
{
    switch (ui->combo_OperatingSystem->currentIndex()) {
        case 0:
            QDesktopServices::openUrl(QUrl("https://javadl.oracle.com/webapps/download/AutoDL?BundleId=243737_61ae65e088624f5aaa0b1d2d801acb16"));
            break;
        case 1:
            QDesktopServices::openUrl(QUrl("https://javadl.oracle.com/webapps/download/AutoDL?BundleId=243737_61ae65e088624f5aaa0b1d2d801acb16"));
            break;
    }
}

void MainWindow::on_button_getPython_clicked()
{
    switch (ui->combo_OperatingSystem->currentIndex()) {
        case 0:
            QDesktopServices::openUrl(QUrl("https://www.python.org/ftp/python/3.9.0/python-3.9.0.exe"));
            break;
        case 1:
            QDesktopServices::openUrl(QUrl("https://www.python.org/ftp/python/3.9.0/python-3.9.0-amd64.exe"));
            break;
    }
}

void MainWindow::on_button_getQGIS_clicked()
{
    switch (ui->combo_OperatingSystem->currentIndex()) {
        case 0:
            QDesktopServices::openUrl(QUrl("https://qgis.org/downloads/QGIS-OSGeo4W-3.16.0-2-Setup-x86.exe"));
            break;
        case 1:
            QDesktopServices::openUrl(QUrl("https://qgis.org/downloads/QGIS-OSGeo4W-3.16.0-2-Setup-x86_64.exe"));
            break;
    }
}

void MainWindow::on_button_getNotepad_clicked()
{
    switch (ui->combo_OperatingSystem->currentIndex()) {
        case 0:
            QDesktopServices::openUrl(QUrl("https://github.com/notepad-plus-plus/notepad-plus-plus/releases/download/v7.9.1/npp.7.9.1.Installer.exe"));
            break;
        case 1:
            QDesktopServices::openUrl(QUrl("https://github.com/notepad-plus-plus/notepad-plus-plus/releases/download/v7.9.1/npp.7.9.1.Installer.x64.exe"));
            break;
    }
}
