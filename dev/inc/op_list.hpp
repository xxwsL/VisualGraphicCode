#pragma once
#ifndef _op_list_hpp_
#define _op_list_hpp_

#include "list_graph.hpp"
#include "image_op_base.hpp"

#include <opencv.hpp>

#include <vector>

#include <qobject.h>
#include <qmessagebox.h>

/*
处理队列对象
*/
class OpList : public QObject
{
	//Q_OBJECT
	/*----------------------------data-------------------------------*/
public:
	/*
	imgCopy ：队列输入图像复制
	vecTask ：队列处理模块容器
	strFile_name ： 原始图像名字
	ptrGraph ： 队列可视化界面对象
	strListName ：队列名字
	*/
	typedef struct {
		cv::Mat imgCopy;
		std::vector<ImageOpBase*> vecTask;
		std::string strFile_name;
		ListGraph *ptrGraph = nullptr;
		std::string strListName;
	}Ustr;

	Ustr mUstr;
	
protected:

	/*----------------------------function-------------------------------*/
public:
	//OpList(void);
	~OpList(void);

	OpList(const cv::Mat& imgSrc_, const std::string& file_name_, const std::string& list_name_);

	/*
	显示备份图像
	*/
	void display_Copy(void) const;

	/*
	显示原始图像
	*/
	void display_Src(void) const;

	/*
	添加模块
	ptr_ ：新模块指针
	seq_ ：新模块插入位置
	*/
	bool add_model(ImageOpBase *ptr_, const int & seq_ = -1);

	/*
	运行处理流程
	*/
	bool run(const size_t& seq_ = 0);

	/*
	显示处理流程界面
	*/
	void display_graph(void) const;

};

#endif