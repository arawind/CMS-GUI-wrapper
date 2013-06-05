#ifndef CMSDIALOG_H
#define CMSDIALOG_H

#include <QWidget>
#include <QProcess>
#include <QSettings>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStringList>
#include <QStatusBar>
#include <QPlainTextEdit>
#include "settings.h"

class cmsdialog : public QWidget
{
    Q_OBJECT
    
public:
    cmsdialog(QWidget *parent = 0);
    void procCall(QStringList);
    QString callCourse();
    ~cmsdialog();
private:
    QProcess *newProc;
    QSettings *settings;
    QVBoxLayout *vert;
    QHBoxLayout *horiz;
    QPushButton *butSync;
    QPushButton *butVersion;
    QPushButton *butCourses;
    QPushButton *butSettings;
    QPlainTextEdit *textarea;
    QStatusBar *statusBar;
    Settings *settingDialog;



private slots:
    void finishedExec(int);
    void sync();
    void courseView();
    void settingSlot();
    void writeToTxt();
    void courseCall(QStringList);
};

#endif // CMSDIALOG_H
