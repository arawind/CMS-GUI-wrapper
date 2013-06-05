#include "courses.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QLabel>
#include <QPushButton>
#include <QInputDialog>
#include <QDebug>

courses::courses(cmsdialog *parent) :
    QDialog(parent)
{
    QVBoxLayout *vert, *vertMain;
    QHBoxLayout *horiz;

    vertMain = new QVBoxLayout();
    vert = new QVBoxLayout();
    horiz = new QHBoxLayout();

    butAdd = new QPushButton("Add");
    butRemove = new QPushButton("Remove");
    butClose = new QPushButton("Close");

    courseList = new QListWidget();
    courseList->setSelectionMode(QAbstractItemView::MultiSelection);


    label = new QLabel("Course list - select the courses and click on Remove for removing");

    horiz->addWidget(courseList);
    vert->addWidget(butAdd);
    vert->addWidget(butRemove);
    vert->addWidget(butClose);
    vert->addStretch();

    horiz->addLayout(vert);

    vertMain->addLayout(horiz);
    this->setLayout(vertMain);


    connect(butAdd, SIGNAL(clicked()), SLOT(add()));
    connect(butRemove, SIGNAL(clicked()), SLOT(remove()));
    connect(butClose, SIGNAL(clicked()), SLOT(close()));

    parentwala = parent;
}

void courses::setData(const QString &data){
    input = QString(data);
    parseData();
}

void courses::parseData(){
    QStringList strList;
    strList = input.split("\n");
    QStringListIterator iterator(strList);
    QString temp;
    courseList->clear();
    iterator.next(); //first line - Viewing Courses
    iterator.next(); //second line  - The following are the courses...
    while(iterator.hasNext()){
        temp = iterator.next();
        if(temp!=""){
            if(temp.split(" ").length()==2)
                courseList->addItem(temp);
        }
    }
}

courses::~courses()
{

}

void courses::refresh(){
    input = this->parentwala->callCourse();
    qDebug() << input << endl;
    parseData();
    //this->close();
}

void courses::add(){
    QStringList courseNames = QInputDialog::getText(this, "Enter Course Names", "Type in the course(s) separated by spaces").split(" ");
    if(courseNames.length()!=0)
        emit clicker(QStringList() << "add" << courseNames);
    refresh();
}

void courses::remove(){
    QStringList courseNames;
    foreach(QListWidgetItem *item, courseList->selectedItems())
        courseNames.append(item->text().split(" "));
    emit clicker(QStringList() << "remove" << courseNames);
    refresh();
}
