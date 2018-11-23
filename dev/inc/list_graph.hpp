#pragma once
#ifndef _list_graph_hpp_
#define _list_graph_hpp_

#include "button.hpp"
#include "image_op_base.hpp"

#include <qwidget.h>
#include <qlayout.h>

#include <vector>

class ListGraph : public QWidget{
	Q_OBJECT
	
	/*----------------------------data-------------------------------*/
public:
	QGridLayout  mLayout;
	std::vector<BUTTON*> vecBUTTON;

	/*----------------------------function-------------------------------*/
public:
	ListGraph(void);
	~ListGraph(void);

	ListGraph(const std::string& name_);

	bool add_button(BUTTON *button_, int seq_ = -1);
};

#endif