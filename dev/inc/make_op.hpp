#pragma once
#ifndef _make_op_hpp_
#define _make_op_gpp_

#include "image_op_inc.hpp"
#include "model_name.hpp"

#include <qlayout.h>
#include <qdialog.h>

#include <vector>

class make_op : QObject{
	Q_OBJECT

	/*----------------------------data-------------------------------*/
public:
	static ImageOpBase *ptrMake_op;
	static int32_t ptrCreate_flag;

public:
	typedef struct {
		QGridLayout *mSelect_layout = nullptr;

		BUTTON *mImg_img_button = nullptr;
		QDialog *mImg_img_dialog = nullptr;
		QGridLayout *mImg_img_layout = nullptr;
	}MAKE_GUI;

	

	static MAKE_GUI mMake_GUI;

	/*----------------------------function-------------------------------*/
public:
	make_op(void);

	~make_op(void);

	static QGridLayout* read_layout_ptr(const int32_t& flag_);

private:
	static void init_GUI(void);

	static void init_button(void);

};

#endif