#pragma once
#ifndef _make_op_hpp_
#define _make_op_gpp_

#include "image_op_inc.hpp"
#include "model_name.hpp"

#include <qlayout.h>
#include <qwidget.h>

class make_op : QObject{
	Q_OBJECT

	/*----------------------------data-------------------------------*/
public:
	static ImageOpBase *ptrMake_op;

public:
	static QGridLayout *mSelect_layout;
	
	static BUTTON *mImg_img_button;
	static QWidget *mImg_img_widget;
	static QGridLayout *mImg_img_layout;

	/*----------------------------function-------------------------------*/
public:
	inline static void init(void);

	inline static void remove_init(void);

private:
	inline static void init_variable(void);

};
#endif