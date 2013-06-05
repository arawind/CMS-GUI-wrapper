#ifndef COURSES_H
#define COURSES_H

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
    explicit courses(QWidget *parent = 0);
    ~courses();
    
private:
    QListWidget *courseList;
    QLabel *label;
    QPushButton *butAdd;
    QPushButton *butRemove;
    QPushButton *butClose;
};

#endif // COURSES_H
