#include "image_op_inc.hpp"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Load_clicked(void)
{
	QString qstrFilename = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image File(*.bmp *.jpg *.jpeg *.png)"));
	QTextCodec *code = QTextCodec::codecForName("gb18030");
	const std::string strName = code->fromUnicode(qstrFilename).data();
	cv::Mat imgRead = cv::imread(strName);
	if (!imgRead.empty() && mManeger.create_Oplist(imgRead, strName))
	{
		cv::cvtColor(imgRead, imgRead, CV_BGR2RGB);
		cv::resize(imgRead, imgRead, cv::Size(ui->label->width(), ui->label->height()));
		imgSrc = QImage((const unsigned char*)(imgRead.data), imgRead.cols, imgRead.rows, imgRead.cols*imgRead.channels(), QImage::Format_RGB888);
		ui->label->clear();
		ui->label->setPixmap(QPixmap::fromImage(imgSrc));
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText(tr("image data is null"));
		msgBox.exec();
	}

}


void MainWindow::on_Gray_clicked(void)
{
	mManeger().add_model(new Gray_op(&mManeger().mUstr.imgCopy));
	mManeger().run();
}

void MainWindow::on_Display_clicked(void) {
	mManeger.display_seq();
}

void MainWindow::on_Graph_clicked(void){
}
