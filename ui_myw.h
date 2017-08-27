/********************************************************************************
** Form generated from reading UI file 'myw.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYW_H
#define UI_MYW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyW
{
public:
    QAction *openFile;
    QAction *CleanS;
    QAction *exitMe;
    QAction *banQuan;
    QAction *aboutMe;
    QAction *jiaMiAction;
    QAction *JieMiAction;
    QAction *saveFile;
    QAction *goSrc;
    QWidget *myArea;
    QLabel *srcPic;
    QLabel *label_3;
    QPushButton *jiaMi;
    QPushButton *jieMi;
    QPushButton *savePic;
    QCheckBox *backSrc;
    QPushButton *View;
    QFrame *line;
    QMenuBar *menuBar;
    QMenu *menu_F;
    QMenu *menu_H;
    QMenu *menu_S;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyW)
    {
        if (MyW->objectName().isEmpty())
            MyW->setObjectName(QStringLiteral("MyW"));
        MyW->resize(1004, 728);
        openFile = new QAction(MyW);
        openFile->setObjectName(QStringLiteral("openFile"));
        CleanS = new QAction(MyW);
        CleanS->setObjectName(QStringLiteral("CleanS"));
        exitMe = new QAction(MyW);
        exitMe->setObjectName(QStringLiteral("exitMe"));
        banQuan = new QAction(MyW);
        banQuan->setObjectName(QStringLiteral("banQuan"));
        aboutMe = new QAction(MyW);
        aboutMe->setObjectName(QStringLiteral("aboutMe"));
        jiaMiAction = new QAction(MyW);
        jiaMiAction->setObjectName(QStringLiteral("jiaMiAction"));
        JieMiAction = new QAction(MyW);
        JieMiAction->setObjectName(QStringLiteral("JieMiAction"));
        saveFile = new QAction(MyW);
        saveFile->setObjectName(QStringLiteral("saveFile"));
        goSrc = new QAction(MyW);
        goSrc->setObjectName(QStringLiteral("goSrc"));
        myArea = new QWidget(MyW);
        myArea->setObjectName(QStringLiteral("myArea"));
        srcPic = new QLabel(myArea);
        srcPic->setObjectName(QStringLiteral("srcPic"));
        srcPic->setGeometry(QRect(30, 80, 951, 591));
        srcPic->setFrameShape(QFrame::Box);
        srcPic->setScaledContents(false);
        srcPic->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(myArea);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(330, 40, 91, 21));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        label_3->setFont(font);
        jiaMi = new QPushButton(myArea);
        jiaMi->setObjectName(QStringLiteral("jiaMi"));
        jiaMi->setGeometry(QRect(70, 20, 101, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(14);
        jiaMi->setFont(font1);
        jieMi = new QPushButton(myArea);
        jieMi->setObjectName(QStringLiteral("jieMi"));
        jieMi->setGeometry(QRect(580, 20, 101, 41));
        jieMi->setFont(font1);
        savePic = new QPushButton(myArea);
        savePic->setObjectName(QStringLiteral("savePic"));
        savePic->setGeometry(QRect(320, 0, 101, 41));
        savePic->setFont(font1);
        backSrc = new QCheckBox(myArea);
        backSrc->setObjectName(QStringLiteral("backSrc"));
        backSrc->setGeometry(QRect(760, 30, 91, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(11);
        backSrc->setFont(font2);
        View = new QPushButton(myArea);
        View->setObjectName(QStringLiteral("View"));
        View->setGeometry(QRect(200, 10, 91, 41));
        line = new QFrame(myArea);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(370, 60, 251, 16));
        line->setStyleSheet(QStringLiteral("border-color: rgb(255, 0, 255);"));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(3);
        line->setFrameShape(QFrame::HLine);
        MyW->setCentralWidget(myArea);
        menuBar = new QMenuBar(MyW);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1004, 23));
        menu_F = new QMenu(menuBar);
        menu_F->setObjectName(QStringLiteral("menu_F"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        menu_S = new QMenu(menuBar);
        menu_S->setObjectName(QStringLiteral("menu_S"));
        MyW->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyW);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MyW->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MyW);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyW->setStatusBar(statusBar);

        menuBar->addAction(menu_F->menuAction());
        menuBar->addAction(menu_S->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menu_F->addAction(openFile);
        menu_F->addAction(saveFile);
        menu_F->addSeparator();
        menu_F->addAction(goSrc);
        menu_F->addAction(CleanS);
        menu_F->addAction(exitMe);
        menu_H->addAction(banQuan);
        menu_H->addAction(aboutMe);
        menu_S->addAction(jiaMiAction);
        menu_S->addAction(JieMiAction);

        retranslateUi(MyW);

        QMetaObject::connectSlotsByName(MyW);
    } // setupUi

    void retranslateUi(QMainWindow *MyW)
    {
        MyW->setWindowTitle(QApplication::translate("MyW", "MyW", Q_NULLPTR));
        openFile->setText(QApplication::translate("MyW", "\346\211\223\345\274\200\345\233\276\347\211\207", Q_NULLPTR));
        CleanS->setText(QApplication::translate("MyW", "\346\270\205\347\251\272\345\233\276\345\203\217\345\214\272\345\237\237", Q_NULLPTR));
        exitMe->setText(QApplication::translate("MyW", "\351\200\200\345\207\272", Q_NULLPTR));
        banQuan->setText(QApplication::translate("MyW", "\347\211\210\346\235\203\345\243\260\346\230\216", Q_NULLPTR));
        aboutMe->setText(QApplication::translate("MyW", "\345\205\263\344\272\216", Q_NULLPTR));
        jiaMiAction->setText(QApplication::translate("MyW", "\345\233\276\345\203\217\345\212\240\345\257\206", Q_NULLPTR));
        JieMiAction->setText(QApplication::translate("MyW", "\n"
"\345\233\276\345\203\217\350\247\243\345\257\206", Q_NULLPTR));
        saveFile->setText(QApplication::translate("MyW", "\344\277\235\345\255\230\345\275\223\345\211\215\345\233\276\345\203\217(&S)", Q_NULLPTR));
        goSrc->setText(QApplication::translate("MyW", "\346\237\245\347\234\213\345\216\237\345\233\276(&Y)", Q_NULLPTR));
        srcPic->setText(QApplication::translate("MyW", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("MyW", "\345\275\223\345\211\215\345\233\276\345\203\217 ", Q_NULLPTR));
        jiaMi->setText(QApplication::translate("MyW", "\345\212\240\345\257\206\357\274\201", Q_NULLPTR));
        jieMi->setText(QApplication::translate("MyW", "\350\247\243\345\257\206\357\274\201", Q_NULLPTR));
        savePic->setText(QApplication::translate("MyW", "\345\255\230\347\233\230", Q_NULLPTR));
        backSrc->setText(QApplication::translate("MyW", "\350\277\224\345\233\236\345\216\237\345\233\276", Q_NULLPTR));
        View->setText(QApplication::translate("MyW", "\346\237\245\347\234\213\345\212\240\345\257\206\345\272\217\345\210\227", Q_NULLPTR));
        menu_F->setTitle(QApplication::translate("MyW", "\346\226\207\344\273\266\357\274\210&F\357\274\211", Q_NULLPTR));
        menu_H->setTitle(QApplication::translate("MyW", "\345\270\256\345\212\251\357\274\210&H\357\274\211", Q_NULLPTR));
        menu_S->setTitle(QApplication::translate("MyW", "\347\237\251\351\230\265\345\212\240\345\257\206\357\274\210&J\357\274\211", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyW: public Ui_MyW {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYW_H
