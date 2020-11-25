#include "riskscapeproject.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

RiskScapeProject::RiskScapeProject(QString projectName, QString homeDirectory) {
    this->projectName = projectName;
    this->homeDirectory = homeDirectory;

    QDir projectDirectory(homeDirectory + "/" + projectName);

    if (projectDirectory.exists()) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Project already exists. Cannot create new project.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setEscapeButton(QMessageBox::Ok);
        msgBox.show();
        if (msgBox.exec() == QMessageBox::Ok) {
            QApplication::quit();
        }
    }
    else {
        projectDirectory.mkdir(homeDirectory + "/" + projectName);
    }

};

bool RiskScapeProject::isValid() {

    QDir projectDirectory(homeDirectory + "/" + projectName);
    if (!projectDirectory.isReadable()) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Invalid directory.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setEscapeButton(QMessageBox::Ok);
        msgBox.show();
        if (msgBox.exec() == QMessageBox::Ok) {
            return false;
        }
    }

    return true;

}

void RiskScapeProject::createDirectory(QString directoryName) {

    QDir directoryToMake;
    directoryToMake.mkdir(homeDirectory + "/" + projectName + "/" + directoryName);

}

void RiskScapeProject::createFile(QString fileName, QString fileLocation) {

    QFile inFile(":/resource/" + fileName);
    QFile outFile;
    if (fileLocation == "") {
        outFile.setFileName(homeDirectory + "/" + projectName + "/" + fileName);
    }
    else {
        outFile.setFileName(homeDirectory + "/" + projectName + "/" + fileLocation + "/" + fileName);
    }
    if (!inFile.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Failed to read " + fileName + " data");
        return ;
    }
    QTextStream textStreamIn(&inFile);
    QString textToAdd = textStreamIn.readAll();
    inFile.close();
    if (!outFile.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Failed to write " + fileName + " data");
        return ;
    }
    QTextStream outText(&outFile);
    outText << textToAdd;
    outFile.flush();
    outFile.close();

}
