#include "myw.h"
#include "ui_myw.h"

MyW::MyW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyW)
{
    ui->setupUi(this);
    QString abc;            QSize  qu= ui->myArea->size();
    abc="Wide:"+QString::number(qu.width(),'g',6)+"\nHigh:"+QString::number(qu.height(),'g',6);
    ui->srcPic->setText(abc);
}

MyW::~MyW()
{    delete ui;}

void MyW::on_banQuan_triggered()//【版权】对话框
{
    QMessageBox::information(this,"版权声明","你好，本程序由孟亚磊及团队成员开发完成。\n版权所有，未经本人许可请勿传播或用于商业用途。");
}

void MyW::on_aboutMe_triggered()//【关于】对话框
{
    QMessageBox::about(this,"关于","本程序为1.0版本。\n开发完成时间：2016年12月。\n开发用途：用于QT和OpenCV的辅助学习。");
}

void MyW::on_openFile_triggered()//打开图像，支持中文文件名
{
    QString wjMing= QFileDialog::getOpenFileName(this,tr("打开图像"),"D:/",tr("图像文件(*.jpg *.jpeg *.png *.bmp)"));
    QTextCodec *code= QTextCodec::codecForName("gb18030");
    std::string name=code->fromUnicode(wjMing).data();          src = imread(name);
    if (src.empty())
    {
        QMessageBox::warning(this,"未选择文件！","对不起，没选择文件！请选一个图像文件打开。");
        return;
    } 
    //将src里面的数据转换为QImage形式（数据、尺寸、颜色模式RGB各8位），存放在QImage对象里。
    yuan=QImage((const unsigned char*)(src.data),src.cols,src.rows,src.step,QImage::Format_RGB888);
    yuan=yuan.rgbSwapped();     //转换颜色顺序成RGB顺序
    yuan=yuan.scaled(QSize(ui->srcPic->width(),ui->srcPic->height()),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->srcPic->setPixmap(QPixmap::fromImage(yuan));
}

void MyW::on_saveFile_triggered()
{
    if (dst.empty()) {
        QMessageBox::warning(this,"没有目标文件！","对不起，目标图像为空！无法进行保存。");        return;
    }
    QString wjMing= QFileDialog::getSaveFileName(this,tr("保存图像"),"D:/",tr("图像文件(*.png *.jpg *.jpeg *.bmp)"));
    QTextCodec *code= QTextCodec::codecForName("gb18030");
    std::string name=code->fromUnicode(wjMing).data();          //获取完整路径和文件名
    imwrite(name,dst);  //直接写入图像。
}

void MyW::on_savePic_clicked()
{
    on_saveFile_triggered();
}

void MyW::on_goSrc_triggered()
{  ui->srcPic->setPixmap(QPixmap::fromImage(yuan));}


void MyW::on_CleanS_triggered()//清空显示
{ui->srcPic->clear();}

void MyW::on_exitMe_triggered()//退出程序
{close();}

void MyW::xianShi()
{
    zhong=QImage((const unsigned char*)(dst.data),dst.cols,dst.rows,dst.step,QImage::Format_RGB888);
    zhong=zhong.rgbSwapped();
    zhong=zhong.scaled(QSize(ui->srcPic->width(),ui->srcPic->height()),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->srcPic->setPixmap(QPixmap::fromImage(zhong));
}

void MyW::on_jiaMi_clicked()
{
    if (src.empty())  {
        QMessageBox::warning(this,"没有图像文件！","对不起，图像为空！无法进行操作。");     return;
    }    
    QFile file("jiami.dat");
    if (true==file.open(QIODevice::ReadOnly)) {//如果读取文件成功，那么读数据到ShunXu向量内
        QDataStream out(&file);
        for(qint16 i=0;i<max;i++)     out>>ShunXu[i];//把文件中的数据依次读入将ShunXu向量。
        file.close();
    }
    else{                                   //如果读取失败，那么就生成序列，并且写入文件。
        if (false==file.open(QIODevice::WriteOnly)) {
            QMessageBox::about(this,"写入失败","对不起，文件写入失败。");       return;
        }
        for(qint16 i=0;i<max;i++)     ShunXu[i]=i;//先生成1到max的顺序向量
        for(qint16 i=0;i<max;i++)                 //然后循环来调换顺序，每次循环执行1或2次调换
        {   //qsrand(max);
            qint16 k=qrand()%max;//k=随机整数对max的余数。
            qint16 m=ShunXu[k];
            ShunXu[k]=ShunXu[i];
            ShunXu[i]=m;            //把随机位置k与当前位置i元素交换位置
            if(k<max-50 && i>100)   //如果满足条件，把i-max与k+50位置的元素交换
            {   m=ShunXu[k+50];
                ShunXu[k+50]=ShunXu[i-100];
                ShunXu[i-100]=m;
            }
        }
        QDataStream out(&file);
        for(qint16 i=0;i<max;i++)     out <<ShunXu[i];//将ShunXu向量中的数据依次写入到数据流/文件。
        file.close();
    }

    Size pp;        //设定加密之后图片新的尺寸
    if(src.cols%max !=0) pp.width=src.cols+max-src.cols%max;        else pp.width=src.cols;
    if(src.rows%max !=0) pp.height=src.rows+max-src.rows%max;       else pp.height=src.rows;
    Mat Mid(pp,src.type());         Mid=Scalar(0,0,0);       //多余的部分填充为黑色
    Mat MidROI=Mid(Rect(0,0,src.cols,src.rows));
    src.copyTo(MidROI);             dst=Mid.clone();
    Mat Map_x(Mid.size(),CV_32FC1),Map_y(Mid.size(),CV_32FC1);//Map_x存放每行的信息，Map_y存放每列的信息

    for(qint16 j=0;j<Mid.rows;j++)
    {    for(qint16 i=0;i<Mid.cols;i++)
        {   Map_x.at<float>(j,i)=i/max*max+ShunXu[i%max];    //例如635，则放到600+（35对应的数字）位置上
            Map_y.at<float>(j,i)=j/max*max+ShunXu[j%max];    //例如199，放到max+  99对应的坐标上
    }   }
    remap(Mid,dst,Map_x,Map_y,INTER_LINEAR,BORDER_CONSTANT,Scalar(0,0,0));
    flip(dst,dst,-1);    xianShi();                         //最后执行水平+垂直翻转
}

void MyW::on_jieMi_clicked()
{
    if (src.empty()){
        QMessageBox::warning(this,"没有图像文件！","对不起，图像为空！无法进行操作。");     return;    }
    Mat Mid;     flip(src,Mid,-1);              //先执行水平垂直翻转，然后才能进行矩阵还原
    Mat Map_x(Mid.size(),CV_32FC1),Map_y(Mid.size(),CV_32FC1);//Map_x存放每行的信息，Map_y存放每列的信息

    QFile file("jiami.dat");
    if (file.open(QIODevice::ReadOnly)) {//如果读取文件成功，那么读数据到ShunXu向量内
        QDataStream out(&file);
        for(qint16 i=0;i<max;i++)     out >>ShunXu[i];//把文件中的数据依次读入将ShunXu向量。
        file.close();
    }
    else{ QMessageBox::about(this,"读取失败","对不起，加密矩阵文件读取失败。");       return;  }

    for (qint16 a=0;a<max;a++)
        for (qint16 c=0;c<max;c++)
            if(a==ShunXu[c])    {  niXiang[a]=c;   break;  }  //首先找到解密的矩阵

    for(qint16 j=0;j<src.rows;j++)
    {    for(qint16 i=0;i<src.cols;i++)
        {   Map_x.at<float>(j,i)=i/max*max+niXiang[i%max];  //例如0，把第70个像素放到0的位置上。
            Map_y.at<float>(j,i)=j/max*max+niXiang[j%max];
   }    }
    remap(Mid,dst,Map_x,Map_y,INTER_LINEAR,BORDER_CONSTANT,Scalar(0,0,0));//恢复出右方和下方有黑边的图像

    Mat lins=dst.clone();   Mid=dst.clone();      //dst克隆2份，lins用于识别边缘，Mid用于提取ROI
    qint16 kuan=dst.cols-max,gao=dst.rows-max;       //找到去掉黑白之外的图像有效宽度和高度
    cvtColor(lins,lins,COLOR_BGR2GRAY);
    threshold(lins,lins,40,255,0);                //必须先进行二值化，然后才能与0进行比较
    for(qint16 j=0;j<dst.rows;j++){                  //从上往下扫描，从右向左扫描
        for(qint16 i=dst.cols-max;i<dst.cols;i++){
            if(lins.at<uchar>(j,i)!=0  && i>kuan )  kuan=i+1;
    }   }
    for(qint16 i=0;i<dst.cols;i++){
        for(qint16 j=dst.rows-max;j<dst.rows;j++){   //从下往上扫描，从左向右扫描。
            if(lins.at<uchar>(j,i)!=0 && j>gao)    gao=j+1;
    }   }
    Mat dstROI=Mid(Rect(0,0,kuan,gao));
    dst=dstROI.clone();     xianShi();
}

void MyW::on_jiaMiAction_triggered()
{

    on_jiaMi_clicked();
}

void MyW::on_JieMiAction_triggered()
{

    on_jieMi_clicked();
}

void MyW::on_backSrc_clicked()
{   if (src.empty())    {
        QMessageBox::warning(this,"没有图像文件！","对不起，图像为空！无法预览。");     return;
    }
    if(ui->backSrc->isChecked())
        on_goSrc_triggered();
    else  xianShi();
}

void MyW::on_View_clicked()
{
    QFile file("jiami.dat");
    if (file.open(QIODevice::ReadOnly)) {//如果读取文件成功，那么读数据到ShunXu向量内
        QDataStream out(&file);     QString abc;
        for(qint16 i=0;i<max;i++)
        {
            out >>ShunXu[i];//把文件中的数据依次读入将ShunXu向量。
            abc+=QString::number(ShunXu[i],'g',6);
            abc+="\t";
        }
        file.close();
        QMessageBox::about(this,"加密矩阵",abc);
    }
    else  QMessageBox::about(this,"读取失败","对不起，加密矩阵文件读取失败。");
}
