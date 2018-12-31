#pragma once
#ifndef _list_graph_hpp_
#define _list_graph_hpp_

#include "button.hpp"
#include "image_op_base.hpp"

#include <qwidget.h>
#include <qlayout.h>

#include <vector>

/*
���п��ӻ��������
*/
class ListGraph : public QWidget{
	Q_OBJECT
	
	/*----------------------------data-------------------------------*/
public:
	/*
	mLayout �����в���
	vecBUTTON �����а�ť����
	*/
	QHBoxLayout mLayout;
	std::vector<BUTTON*> vecBUTTON;

	/*----------------------------function-------------------------------*/
public:
	ListGraph(void);
	~ListGraph(void);

	ListGraph(const std::string& name_);

	/*
	��Ӱ�ť
	button_ ����ťָ��
	seq_ : ��ť����λ��
	*/
	bool add_button(BUTTON *button_, int seq_ = -1);
};

#endif