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

//定义一个全局变量
QString path;

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

    //初始化，默认显示utf-8
    flag = utf_8;
    //设置编码，这里设置UTF-8编码
    //codec = QTextCodec::codecForName("UTF-8");
    codec = QTextCodec::codecForName("GBK");

    path = "";
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
    ui->label->setText("编码：UTF-8");
    //ui->label->setText(codec->toUnicode("编码：UTF-8"));
    //ui->label->setText(codec->fromUnicode("编码：UTF-8"));
}

void MainWindow::on_actionGbk_triggered()
{
    //gbk编码
    flag = gbk;
    //标签显示gbk
    ui->label->setText("编码：GBK");
    //ui->label->setText(codec->toUnicode("编码：GBK"));
    //ui->label->setText(codec->fromUnicode("编码：GBK"));
}

//打开文件处理函数
void MainWindow::on_actionOpen_triggered()
{
    //1、打开一个文件，获取文件的路径
    //QString path = QFileDialog::getOpenFileName();
    path = QFileDialog::getOpenFileName();

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

//文件另存为
void MainWindow::on_actionSave_as_triggered()
{
    //1、选择一个文件路径，路径是qt得到的，编码为utf-8，返回值类型是QString
    //QString path = QFileDialog::getSaveFileName();
    path = QFileDialog::getSaveFileName();
    if(path.isEmpty())
    {
        return;
    }

    //2、需要将utf-8转换gbk，再将QString转换为char *
    const char *fileName = codec->fromUnicode(path).data();

    //3、打开文件路径，fopen，需要的路径是char *，如果有中文需要gbk
    FILE *fp = fopen(fileName, "wb");
    if(fp == NULL)
    {
        cout << "on_actionSave_as_triggered fopen err";
        return;
    }

    //4、获取编辑区的内容
    QString str = ui->textEdit->toPlainText();

    //5、将编辑区的内容类型QString转换为char *
    const char *buf = str.toStdString().data();

    //6、将编辑区的内容写入文件fputs()
    fputs(buf, fp);

    //7、关闭文件
    fclose(fp);
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionComplie_triggered()
{
    //路径带空格无法编译成功
    //system("gcc E:\\liu workstations\\tmp_file\\temp_file_1\\a.c -o E:\\liu workstations\\tmp_file\\temp_file_1\\a");

    //system("gcc E:\\liu\\c\\demo\\a.c -o E:\\liu\\c\\demo\\a");
    //system("cmd /k E:\\liu\\c\\demo\\a");

    if(path.isEmpty())
    {
        //cout << "path is empty";
        return;
    }
    QString demo = path;
    //把.c替换成空字符
    demo.replace(".c", "");
    QString cmd = QString("gcc %1 -o %2").arg(path).arg(demo);
    //如果有中文需要将utf-8转换gbk，再将QString转换为char *
    int ret = system(codec->fromUnicode(cmd).data());
    //ret成功返回0
    if(ret != 0)
    {
        return;
    }

    //运行程序
    QString target = QString("cmd /k %1").arg(demo);

    //如果有中文需要将utf-8转换gbk，再将QString转换为char *
    system(codec->fromUnicode(target));
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

void MainWindow::on_actionNew_file_triggered()
{
    //清空内容
    ui->textEdit->clear();//1
    //ui->textEdit->setText("");//2

    //清空路径
    path.clear();//1
    //path = "";//2
}

void MainWindow::on_actionSave_triggered()
{
    //1、路径为空，没有选择文件，需要选择文件
    if(path.isEmpty())
    {
        path = QFileDialog::getSaveFileName();
        if(path.isEmpty())
        {
            return;
        }
    }

    //2、路径不为空，说明已经打开了文件，需要把内容写入保存原来的路径文件里
    //a、打开文件
    //b、获取内容
    //c、保存内容
    //d、关闭文件

    //2、需要将utf-8转换gbk，再将QString转换为char *
    const char *fileName = codec->fromUnicode(path).data();

    //3、打开文件路径，fopen，需要的路径是char *，如果有中文需要gbk
    FILE *fp = fopen(fileName, "wb");
    if(fp == NULL)
    {
        cout << "on_actionSave_as_triggered fopen err";
        return;
    }

    //4、获取编辑区的内容
    QString str = ui->textEdit->toPlainText();

    //5、将编辑区的内容类型QString转换为char *
    const char *buf = str.toStdString().data();

    //6、将编辑区的内容写入文件fputs()
    fputs(buf, fp);

    //7、关闭文件
    fclose(fp);
}
