#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //ui->GUESS->setDisabled(1);
        ui->RESET->setDisabled(1);
    int temp =  ReturnRandomNum();
    qDebug()<< "Number is "  << temp;

    ui->CorrectOrNot->setText("Enter A Number!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::ReturnRandomNum()
{
    seed = time(0);
    srand(seed);
    secretnumber = (rand()%(20-10+1)+10);
    return secretnumber;
}




void MainWindow::on_GUESS_clicked()
{
    //   qDebug() << "Connection Working ";
    // ui->GUESS->setDisabled(0);

    guessnumber = ui->spinBox->value();
     ui->RESET->setDisabled(0);

    // qDebug() << "The value rtains as : " << guessnumber;
    if(guessnumber>secretnumber)
    {
        ui->CorrectOrNot->setText("Too High!");

    }
    else if(guessnumber< secretnumber)
    {
        ui->CorrectOrNot->setText("Too Low");
    }
    else
    {
        ui->GUESS->setDisabled(1);
        ui->CorrectOrNot->setText("CORRECT! You Guessed : " + QString::number(guessnumber));
        ui->spinBox->setValue(0);

    }


}


void MainWindow::on_RESET_clicked()
{
    ui->GUESS->setDisabled(0);

    ui->CorrectOrNot->setText("Let's GO! ");
    int temp =  ReturnRandomNum();
    guessnumber = ui->spinBox->value();
    qDebug()<< "Number is "  << temp;
    //on_GUESS_clicked();

}






//Features TO Add
//Winning Streak!
//Custom Messages On Wrong Answers
//Name Of Player


