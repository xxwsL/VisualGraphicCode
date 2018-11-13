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
		cv::Mat *imgIn = nullptr;
		cv::Mat *imgOut = nullptr;
	}USTR;

	USTR mUstr;
	/*----------------------------function-------------------------------*/
public:
	Gray_op(void);
	~Gray_op(void);

	Gray_op(cv::Mat *ptrIn_, cv::Mat *ptrOut_);

	virtual bool op(void *ustr_) const;
};

#endif