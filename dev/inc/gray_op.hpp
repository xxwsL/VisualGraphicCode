#pragma once
#ifndef _gray_op_hpp_
#define _gray_op_hpp_

#include <opencv.hpp>

#include <qwidget.h>
#include <qmessagebox.h>

#include "image_op_base.hpp"
#include "button.hpp"
#include "model_name.hpp"

class Gray_op : public ImageOpBase
{
	/*----------------------------data-------------------------------*/
public:
	/*
	TYPE : 模块类型
	mInterface ：模块接口
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
	Gray_op(void);
	~Gray_op(void);

	image_op_base_fi

};

#endif