#pragma once
#ifndef _list_graph_hpp_
#define _list_graph_hpp_

#include "button.hpp"
#include "image_op_base.hpp"

#include <qwidget.h>
#include <qlayout.h>

#include <vector>

/*
队列可视化界面对象
*/
class ListGraph : public QWidget{
	Q_OBJECT
	
	/*----------------------------data-------------------------------*/
public:
	/*
	mLayout ：队列布局
	vecBUTTON ：队列按钮容器
	*/
	QHBoxLayout mLayout;
	std::vector<BUTTON*> vecBUTTON;

	/*----------------------------function-------------------------------*/
public:
	ListGraph(void);
	~ListGraph(void);

	ListGraph(const std::string& name_);

	/*
	添加按钮
	button_ ：按钮指针
	seq_ : 按钮插入位置
	*/
	bool add_button(BUTTON *button_, int seq_ = -1);
};

#endif