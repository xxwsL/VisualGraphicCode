#pragma once
#ifndef _list_graph_hpp_
#define _list_graph_hpp_

#include "button.hpp"
#include "image_op_base.hpp"

#include <qdialog.h>
#include <qlayout.h>

#include <vector>

class ListGraph : public QDialog{
	Q_OBJECT
	
	/*----------------------------data-------------------------------*/
public:
	QGridLayout  *mLayout;
	std::vector<BUTTON*> vecBUTTON;

	/*----------------------------function-------------------------------*/
public:
	ListGraph(void);
	~ListGraph(void);

	bool create_button(std::vector<ImageOpBase*>& vec_);

};

#endif