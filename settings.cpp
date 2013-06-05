#include "settings.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QFileDialog>
//#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent)//,
    //ui(new Ui::Settings)
{
    //UI
    this->setWindowTitle("Wrapper Settings");
    vert = new QVBoxLayout();
    horiz = new QHBoxLayout();

    butOK = new QPushButton("OK");
    butOK->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    butCancel = new QPushButton("Cancel");
    butCancel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    butOpen = new QPushButton("Open");

    fileName = new QLineEdit();

    label = new QLabel("Select the CourseSync executable");

    vert->addWidget(label);
    horiz->addWidget(fileName);
    horiz->addWidget(butOpen);

    vert->addLayout(horiz);

    horiz = new QHBoxLayout();

    horiz->addStretch();

    horiz->addWidget(butOK);
    horiz->addWidget(butCancel);
    //horiz->addStretch();

    vert->addLayout(horiz);

    this->setLayout(vert);

    connect(butOpen, SIGNAL(clicked()), SLOT(openFile()));
    connect(butOK, SIGNAL(clicked()), SLOT(accept()));
    connect(butCancel, SIGNAL(clicked()), SLOT(reject()));

    //END UI

    //ui->setupUi(this);
}

Settings::~Settings()
{
    //delete ui;
}

void Settings::openFile(){
    fileName->setText(QFileDialog::getOpenFileName(this,"Select CourseSync executable",QDir::homePath(),""));
}

QString Settings::getPath(){
    return fileName->text();
}
