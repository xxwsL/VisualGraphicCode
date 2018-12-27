#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "OpList_manege.hpp"

#include <QMainWindow>

#include <opencv.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

	/*----------------------------data-------------------------------*/
public:
	//������й�����
	OpListManege mManeger;

private:
	//QT����ԭʼimage
	QImage imgSrc;

	/*----------------------------function-------------------------------*/
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
	
	void on_Load_clicked(void);

	void on_Run_clicked(void);

	void on_Display_clicked(void);

	void on_Graph_clicked(void);

private:
	Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
