#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QDialog (parent)

{
    for(int i=0;i<STUDENT_CNT;i++)
    {
        vector.push_back(QVector<int>());
        vector[i].resize(MARK_CNT);
    }

    l=new QLabel*[MARK_CNT];
    current=new QLabel("CURRENT");

    sb=new QSpinBox*[MARK_CNT];
    edit=new QLabel("EDIT");

    cb=new QComboBox;
    for(int i(0);i<STUDENT_CNT;i++)
    {
        cb->addItem("Student"+ QString::number(i) );
    }

    ok=new QPushButton("OK");
    exit=new QPushButton("EXIT");

    QVBoxLayout* lables=new QVBoxLayout;
    lables->addWidget(current);
    for(int i(0);i<MARK_CNT;i++)
    {
        l[i]=new QLabel;
        lables->addWidget(l[i]);
    }

    QVBoxLayout* spin_boxes=new QVBoxLayout;
    spin_boxes->addWidget(edit);
    for(int i(0);i<MARK_CNT;i++)
    {
        sb[i]=new QSpinBox;
        spin_boxes->addWidget(sb[i]);
        sb[i]->setMaximum(10);
        sb[i]->setMinimum(1);
    }

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
    int k=cb->currentIndex();
    for(int i(0);i<MARK_CNT;i++)
    {
        vector[k].replace(i,sb[i]->value());
        l[i]->setText(QString::number(sb[i]->value()));
    }


}
void MainWindow::BoxChanged()
{
    int k=cb->currentIndex();
    for(int i(0);i<MARK_CNT;i++)
    {

        if(vector [k][i]<=10 && vector [k][i]>=1)
        {
            l[i]->setText(QString::number(vector[k][i]));
        }

        else
        {
            l[i]->setText("Undefined");
        }

        sb[i]->setValue(1);
    }

}
MainWindow::~MainWindow()
{
    delete sb;
    delete l;
}
