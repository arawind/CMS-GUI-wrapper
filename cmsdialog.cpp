#include "cmsdialog.h"
#include <QProcess>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QStatusBar>
#include <QPlainTextEdit>
#include "settings.h"
#include "courses.h"
#include <QDebug>

cmsdialog::cmsdialog(QWidget *parent)
    : QWidget(parent)
{
    //UI
    vert = new QVBoxLayout();
    horiz = new QHBoxLayout();

    butSync = new QPushButton("Sync");
    butCourses = new QPushButton("View Courses");
    butSettings = new QPushButton("Settings");

    textarea = new QPlainTextEdit();

    statusBar = new QStatusBar();

    horiz->addWidget(butSync);
    horiz->addWidget(butCourses);

    vert->addLayout(horiz);

    vert->addWidget(textarea);

    horiz = new QHBoxLayout();
    horiz->addWidget(butSettings);

    vert->addLayout(horiz);

    vert->addWidget(statusBar);

    this->setLayout(vert);

    //END UI

    //SIGNALS SLOTS
    connect(butSync, SIGNAL(clicked()), SLOT(sync()));
    connect(butCourses, SIGNAL(clicked()), SLOT(courseView()));
    connect(butSettings, SIGNAL(clicked()), SLOT(settingSlot()));
    //END SIGNALS SLOTS

    settings = new QSettings("arawind","CourseSync Wrapper");
    QString execPath = settings->value("paths/executable","Please set path to CourseSync executable").toString();
    statusBar->showMessage(execPath);

}

void cmsdialog::finishedExec(int a){
    //QMessageBox mssg;
    //QByteArray output = newProc->readAll();
    //mssg.setText(output);
    //mssg.exec();
    newProc->disconnect();
}

cmsdialog::~cmsdialog()
{
    
}

void cmsdialog::courseView(){
    textarea->clear();
    textarea->appendPlainText("Viewing Courses");
    procCall(QStringList()<<"courses");
    if(newProc->waitForFinished()){
        courses newCourseDialog(this);
        newCourseDialog.setData(textarea->toPlainText());
        connect(&newCourseDialog, SIGNAL(clicker(QStringList)), this, SLOT(courseCall(QStringList)));
        newCourseDialog.setModal(true);
        newCourseDialog.exec();

    }
}

void cmsdialog::sync(){
    textarea->clear();
    textarea->appendPlainText("Syncing Courses");
    procCall(QStringList()<<"sync");
}

void cmsdialog::procCall(QStringList arguments){
    QString program = settings->value("paths/executable","").toString();

    if(program!=""){
        qDebug()<< "inhere" <<endl;
        newProc = new QProcess();
        connect(newProc,SIGNAL(finished(int)), SLOT(finishedExec(int)));
        connect(newProc, SIGNAL(readyReadStandardOutput()), SLOT(writeToTxt()));
        newProc->start(program, arguments);
    }
}

void cmsdialog::writeToTxt(){
    QByteArray output = newProc->readAllStandardOutput();

    textarea->appendPlainText(output);
}

void cmsdialog::settingSlot(){
    Settings settingDialog;
    settingDialog.setModal(true);
    if(settingDialog.exec()==QDialog::Accepted){
        settings->setValue("paths/executable", settingDialog.getPath());
        statusBar->showMessage(settingDialog.getPath());
    }
}

QString cmsdialog::callCourse(){
    textarea->clear();
    textarea->appendPlainText("Viewing Courses");
    procCall(QStringList()<<"courses");
    if(newProc->waitForFinished()){
        return textarea->toPlainText();
    }
    return "";
}

void cmsdialog::courseCall(QStringList arguments){
    textarea->clear();
    procCall(arguments);
    if(newProc->waitForFinished())
        qDebug() << arguments.join(" ") << endl;
}
