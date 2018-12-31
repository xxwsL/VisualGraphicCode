#pragma once
#ifndef _in_out_op_hpp_
#define _in_out_op_hpp_

#include "image_op_base.hpp"
#include "model_name.hpp"
#include "button.hpp"

#include <qdialog.h>
#include <qmessagebox.h>


class IO_op : public QDialog, public ImageOpBase
{
	Q_OBJECT
	/*----------------------------data-------------------------------*/
public:

	/*
	TYPE ： 模块类型
	imgptr ：模块数据
	mButton ：模块按钮
	*/
	typedef struct {
		int32_t* TYPE;
		std::string *strName;
		ImageOpBase::IMG_IMG_INTERFACE mInterface;
		BUTTON mButton;
	}USTR;

	USTR mUstr;
	/*----------------------------function-------------------------------*/
public:
	//IO_op(void);
	~IO_op(void);

	IO_op(const cv::Mat& ptr_img_);
	
	image_op_base_fi

};

#endif