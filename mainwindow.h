#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define STUDENT_CNT 5
#define MARK_CNT 5

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
  ~MainWindow();
private:
   QLabel **l,*current,*edit;
   QSpinBox **sb;
   QComboBox *cb;
   QPushButton *ok,*exit;
   QVector <QVector<int>> vector;
private slots:

   void OkPressed();
   void BoxChanged();

};

#endif // MAINWINDOW_H
