#pragma once
#ifndef _gray_op_hpp_
#define _gray_op_hpp_

#include <opencv.hpp>

#include "image_op_base.hpp"

class Gray_op : public ImageOpBase
{
	/*----------------------------data-------------------------------*/
public:
	typedef struct {
		size_t TYPE;
		cv::Mat *imgIn = nullptr;
		cv::Mat imgOut;
	}USTR;

	USTR mUstr;
	/*----------------------------function-------------------------------*/
public:
	//Gray_op(void);
	~Gray_op(void);

	Gray_op(cv::Mat *ptrIn_);

	virtual bool op(void);

	virtual bool display(void);
};

#endif