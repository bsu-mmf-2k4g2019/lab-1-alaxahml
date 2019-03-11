#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QDialog (parent)

{

    for(int i=0;i<3;i++)
    {
      vector.push_back(QVector<int>());
      vector[i].resize(3);
    }

    l1=new QLabel;
    l2=new QLabel;
    l3=new QLabel;
    current=new QLabel("CURRENT");

    sb1=new QSpinBox;
    sb1->setMaximum(10);
    sb1->setMinimum(1);
    sb2=new QSpinBox;
    sb2->setMaximum(10);
    sb2->setMinimum(1);
    sb3=new QSpinBox;
    sb3->setMaximum(10);
    sb3->setMinimum(1);
    edit=new QLabel("EDIT");

    cb=new QComboBox;
    cb->addItem("Иванов Иван");
    cb->addItem("Петров Петр");
    cb->addItem("Сидоров Сидор");

    ok=new QPushButton("OK");
    exit=new QPushButton("EXIT");


   QVBoxLayout* lables=new QVBoxLayout;
   lables->addWidget(current);
   lables->addWidget(l1);
   lables->addWidget(l2);
   lables->addWidget(l3);

   QVBoxLayout* spin_boxes=new QVBoxLayout;
   spin_boxes->addWidget(edit);
   spin_boxes->addWidget(sb1);
   spin_boxes->addWidget(sb2);
   spin_boxes->addWidget(sb3);

   QHBoxLayout* combo_box=new QHBoxLayout;
   combo_box->addWidget(cb);

   QHBoxLayout* buttons=new QHBoxLayout;
   buttons->addWidget(ok);
   buttons->addWidget(exit);

   QVBoxLayout* right_side=new QVBoxLayout;
   right_side->addLayout(combo_box);
   right_side->addLayout(buttons);

   QHBoxLayout* mainlayout=new QHBoxLayout;
   mainlayout->addLayout(lables);
   mainlayout->addLayout(spin_boxes);
   mainlayout->addLayout(right_side);

   setLayout(mainlayout);

   connect(exit,SIGNAL(clicked()),this,SLOT(close()));
   connect(ok,SIGNAL(clicked()),this,SLOT(OkPressed()));
   connect(cb,SIGNAL(currentIndexChanged(QString)),this,SLOT(BoxChanged()));
}
void MainWindow::OkPressed()
{
    int i=cb->currentIndex();

   vector[i].replace(0,sb1->value());
   vector[i].replace(1,sb2->value());
   vector[i].replace(2,sb3->value());
   l1->setText(QString::number(sb1->value()));
   l2->setText(QString::number(sb2->value()));
   l3->setText(QString::number(sb3->value()));

}
void MainWindow::BoxChanged()
{
     int i=cb->currentIndex();

    if(vector [i][0]<=10 && vector [i][0]>=1)
   l1->setText(QString::number(vector[i][0]));
   else
   l1->setText("Undefined");
   sb1->setValue(1);

    if(vector [i][1]<=10 && vector [i][1]>=1)
   l2->setText(QString::number(vector[i][1]));
    else
    l2->setText("Undefined");
    sb2->setValue(1);

    if(vector [i][2]<=10 && vector [i][2]>=1)
   l3->setText(QString::number(vector[i][2]));
    else
    l3->setText("Undefined");
    sb3->setValue(1);

}
