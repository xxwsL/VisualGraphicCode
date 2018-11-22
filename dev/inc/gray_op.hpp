#pragma once
#ifndef _gray_op_hpp_
#define _gray_op_hpp_

#include <opencv.hpp>

#include <qwidget.h>

#include "image_op_base.hpp"
#include "button.hpp"

class Gray_op : public ImageOpBase
{
	/*----------------------------data-------------------------------*/
public:
	typedef struct {
		std::pair<int* , std::string*>  TYPE;
		cv::Mat *imgIn = nullptr;
		cv::Mat imgOut;
		BUTTON mButton;
	}USTR;

	USTR mUstr;
	/*----------------------------function-------------------------------*/
public:
	//Gray_op(void);
	~Gray_op(void);

	Gray_op(cv::Mat *ptrIn_);

	virtual bool op(void);

	virtual bool display(void);

	virtual BUTTON* read_button(void);
};

#endif