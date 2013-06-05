#ifndef COURSES_H
#define COURSES_H
#include "cmsdialog.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QLabel>
#include <QPushButton>
class courses : public QDialog
{
    Q_OBJECT
    
public:
    explicit courses(cmsdialog *parent = 0);
    void setData(const QString &);
    ~courses();
signals:
    void clicker(QStringList);
private:
    QListWidget *courseList;
    QLabel *label;
    QPushButton *butAdd;
    QPushButton *butRemove;
    QPushButton *butClose;
    void parseData();
    void refresh();
    QString input;
    cmsdialog *parentwala;

private slots:
    void add();
    void remove();

};

#endif // COURSES_H
