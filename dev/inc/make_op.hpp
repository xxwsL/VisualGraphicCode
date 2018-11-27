#pragma once
#ifndef _make_op_hpp_
#define _make_op_gpp_

#include "image_op_inc.hpp"
#include "model_name.hpp"

#include <qlayout.h>
#include <qdialog.h>

class make_op : QObject{
	Q_OBJECT

	/*----------------------------data-------------------------------*/
public:
	static ImageOpBase *ptrMake_op;

public:
	static QGridLayout *mSelect_layout;
	
	static BUTTON *mImg_img_button;
	static QDialog *mImg_img_widget;
	static QGridLayout *mImg_img_layout;

	/*----------------------------function-------------------------------*/
public:
	make_op(void);

	~make_op(void);

	static QGridLayout* get_layout(const int32_t& flag_);
private:
	inline static void init_variable(void);

};
#endif