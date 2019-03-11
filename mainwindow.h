#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QDialog>
#include<QPushButton>
#include<QComboBox>
#include<QLabel>
#include<QSpinBox>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QVector>
#include<QMessageBox>

class MainWindow : public QDialog
{
    Q_OBJECT

public:
  MainWindow(QWidget *parent=nullptr);
private:
   QLabel *l1,*l2,*l3,*current,*edit;
   QSpinBox *sb1,*sb2,*sb3;
   QComboBox *cb;
   QPushButton *ok,*exit;
   QVector <QVector<int>> vector;
private slots:
   void OkPressed();
   void BoxChanged();

};

#endif // MAINWINDOW_H
