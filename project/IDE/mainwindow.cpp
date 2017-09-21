#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTextCodec>
#include <QFileDialog>//文件对话框
#include <string.h>
#define cout qDebug() //定义宏，cout是c++的打印输出

enum Mycode
{
    utf_8,gbk
};

//定义一个枚举变量
enum Mycode flag;

//定义一个字符编码指针
QTextCodec *codec;

//构造函数
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //cout << "hello qt";//打印输出

    //QLabel操作，给label设置内容
    //ui->label->setText("编码：UTF-8");

    //获取label标签的内容，返回值类型：QString
    //QString str;
    //str = ui->label->text();
    //cout << str;

    //QTextEdit操作，给编辑区设置内容
    //ui->textEdit->setText("This is a program");
    //获取label标签的内容，返回值类型：QString
    //str = ui->textEdit->toPlainText();
    //cout << str;

    flag = utf_8;
    //设置编码，这里设置UTF-8编码
    codec = QTextCodec::codecForName("UTF-8");
}

//析构函数
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionUtf_8_triggered()
{
    //utf-8编码
    flag = utf_8;
    //标签显示utf-8
    ui->label->setText(codec->toUnicode("编码：UTF-8"));
}

void MainWindow::on_actionGbk_triggered()
{
    //gbk编码
    flag = gbk;
    //标签显示gbk
    ui->label->setText(codec->toUnicode("编码：GBK"));
}

//打开文件处理函数
void MainWindow::on_actionOpen_triggered()
{
    //1、打开一个文件，获取文件的路径
    QString path = QFileDialog::getOpenFileName();

    if(path.isEmpty())//Qt处理如果没有选择文件
    {
        return;
    }

    //2、由于通过Qt控件获取的路径，此路径是utf-8编码
    //同时将QString转换为char *
    char *fileName = codec->fromUnicode(path).data();

    //3、打开文件，fopen(),fopen()如果有中文,需要gbk编码
    FILE *fp = fopen(fileName, "rb");
    if(fp == NULL)
    {
        cout << "on_actionOpen_triggered fopen err";
        return;
    }

    //4、循环读取文件内容fgets(),内容是char *
    char buf[1024];
    QString str;
    while(1)
    {
        memset(buf, 0, sizeof(buf));
        fgets(buf, sizeof(buf), fp);

        if(flag == utf_8)
        {
            str = str + buf;
        }
        else if(flag == gbk)
        {
            //将读取的字符gbk转换成utf-8
            str = str + codec->toUnicode(buf);
        }

        if(feof(fp))
        {
            break;
        }
    }

    //5、需要把读取的内容显示到编辑区里，setText
    ui->textEdit->setText(str);

    //6、关闭文件
    fclose(fp);
}
