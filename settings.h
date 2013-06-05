#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QFileDialog>

/*namespace Ui {
class Settings;
}*/

class Settings : public QDialog
{
    Q_OBJECT
    
public:
    explicit Settings(QWidget *parent = 0);
    QString getPath();
    ~Settings();

private:
    //Ui::Settings *ui;
    QVBoxLayout *vert;
    QHBoxLayout *horiz;
    QPushButton *butOK;
    QPushButton *butCancel;
    QPushButton *butOpen;
    QLabel *label;
    QLineEdit *fileName;
private slots:
    void openFile();

};

#endif // SETTINGS_H
