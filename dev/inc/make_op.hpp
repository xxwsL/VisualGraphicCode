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

public:
	typedef struct {
		QGridLayout *mSelect_layout = nullptr;

		BUTTON *mImg_img_button = nullptr;
		QDialog *mImg_img_dialog = nullptr;
		QGridLayout *mImg_img_layout = nullptr;
	}MAKE_GUI;

	typedef struct {
	}BUTTON_VEC_LIST;

	static MAKE_GUI mMake_GUI;
	//static BUTTON_VEC_LIST mButton_vec_list;
	/*----------------------------function-------------------------------*/
public:
	make_op(void);

	~make_op(void);

	static QGridLayout* get_layout(const int32_t& flag_);

	void load_creater(void);

private:
	static void init_GUI(void);

	static void init_button(void);

};

#endif