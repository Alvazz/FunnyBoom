#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stttopsideframe.h"
#include "sttdownsideframe.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUI()
{
    topsideFrame = new STTTopSideFrame();
    ui->topStackedWidget->addWidget(topsideFrame);

    downsideFrame = new STTDownSideFrame();
    ui->downStackedWidget->addWidget(downsideFrame);
}
