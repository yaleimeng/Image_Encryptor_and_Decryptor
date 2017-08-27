#ifndef MYW_H
#define MYW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QAction>
#include <QDialog>
#include <QFile>
#include <QDataStream>
#include <QFileDialog>
#include <QDir>
#include <vector>
#include <QTextCodec>
#include <QPushButton>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;


namespace Ui {
class MyW;   }

class MyW : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyW(QWidget *parent = 0);
    ~MyW();
    Mat src,dst;     QImage yuan,zhong;
    const qint16 max=1000;
    qint16 ShunXu[1000],niXiang[1000];  //此处确定了加密序列的长度，可以调节。


private slots:
    void xianShi();
    void on_banQuan_triggered();
    void on_aboutMe_triggered();
    void on_openFile_triggered();
    void on_CleanS_triggered();
    void on_exitMe_triggered();
    void on_jiaMi_clicked();
    void on_jieMi_clicked();
    void on_jiaMiAction_triggered();
    void on_JieMiAction_triggered();
    void on_saveFile_triggered();
    void on_savePic_clicked();
    void on_goSrc_triggered();
    void on_backSrc_clicked();

    void on_View_clicked();

private:
    Ui::MyW *ui;
};

#endif // MYW_H
