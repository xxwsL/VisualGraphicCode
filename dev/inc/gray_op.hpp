#pragma once
#ifndef _gray_op_hpp_
#define _gray_op_hpp_

#include <opencv.hpp>

#include <qwidget.h>
#include <qmessagebox.h>

#include "image_op_base.hpp"
#include "button.hpp"

class Gray_op : public ImageOpBase
{
	/*----------------------------data-------------------------------*/
public:
	typedef struct {
		std::pair<int* , std::string*>  TYPE;
		ImageOpBase::IMG_IMG_INTERFACE mInterface;
		BUTTON mButton;
	}USTR;

	USTR mUstr;
	/*----------------------------function-------------------------------*/
public:
	Gray_op(void);
	~Gray_op(void);

	Gray_op(cv::Mat *ptrIn_);

	image_op_base_fi

	static ImageOpBase* create(int32_t *flag_);
};

#endif