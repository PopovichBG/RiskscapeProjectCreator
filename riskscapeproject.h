#ifndef RISKSCAPEPROJECT_H
#define RISKSCAPEPROJECT_H
#include <QMainWindow>
#include <iostream>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QDir>

class RiskScapeProject
{
private:
    QString projectName;
    QString homeDirectory;
public:
    RiskScapeProject(QString projectName, QString homeDirectory);
    void createDirectory(QString directoryName);
    void createFile(QString fileName, QString fileLocation);
    bool isValid();
};

#endif // RISKSCAPEPROJECT_H
