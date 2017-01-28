#include "table.h"
#include "ui_table.h"

float case_personal(QString sign, QString num1, QString num2)
{
    double num11 = num1.toInt();
    double num21 = num2.toInt();
    if (sign == QString("+"))
        return num11+num21;
    if (sign == QString("-"))
        return num11-num21;
    if (sign == QString("*"))
        return num11*num21;
    if (sign == QString("/"))
        return num11/num21;
}

Table::Table(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);
}

Table::~Table()
{
    delete ui;
}

void Table::on_pushButton_8_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + QString("1"));
}

void Table::on_pushButton_9_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + QString("2"));
}

void Table::on_pushButton_10_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + QString("3"));
}

void Table::on_pushButton_5_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + QString("4"));
}

void Table::on_pushButton_6_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + QString("5"));
}

void Table::on_pushButton_7_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + QString("6"));
}

void Table::on_pushButton_2_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + QString("7"));
}

void Table::on_pushButton_3_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + QString("8"));
}

void Table::on_pushButton_4_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + QString("9"));
}

void Table::on_pushButton_15_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + QString("0"));
}

void Table::on_pushButton_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void Table::on_pushButton_14_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + QString("+"));
}

void Table::on_pushButton_13_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + QString("-"));
}

void Table::on_pushButton_12_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + QString("*"));
}

void Table::on_pushButton_11_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + QString("/"));
}

void Table::on_pushButton_16_clicked()
{
    QString text = ui->lineEdit->text();
    text.chop(1);
    ui->lineEdit->setText(text);
}

void Table::on_pushButton_17_clicked()
{
//    QFile file1("C:/projects/Calculator/file1.txt");
//    file1.open(QIODevice::WriteOnly | QIODevice::Text);
//    QTextStream outs(&file1);

    int j=0;
    QString text = ui->lineEdit->text();
//    outs << text << "TEXT" << '\n';
    QString numbers[11];
    double gain;
    QString sighn[10];


    QString m;
    for(int i=0; i<text.length(); i++)
    {
        m=text[i];
//        outs << m << "M" << "    ";
        if((m == QString("+"))||(m == QString("-"))||(m == QString("/"))||(m == QString("*")))
        {
            sighn[j] = m;
//            outs << sighn[j] << "SIGN" << '\n';
            j++;
        }
        else
        {
            numbers[j]+=m;
//            outs << numbers[j] << "NUMBER" << '\n';
        }
    }

//    for(int i=0; i<j; i++)
//    {
//        outs << numbers[i] << "NUMBER" << "  ";
//        outs << sighn[i] << "SIGN" << '\n';
//    }
//    outs << numbers[j] << "NUMBER" << '\n';
//    outs << text.length() << '\n';
//    outs << j ;
    double foo;
    for(int i=0; i<j; i++)
    {
        foo = case_personal(sighn[i], numbers[i], numbers[i+1]);
        numbers[i+1] = QString::number(foo);
//        outs<< i << "I"  << numbers[i] << "NUMBER1" << numbers[i+1] << "NUMBER2" << foo << "FOO" << '\n';
    }
    ui->lineEdit_2->setText(numbers[j]);
//    file1.close();
}
