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

	BUTTON mButton;

	typedef struct {
		std::pair<int32_t*, std::string*> TYPE;
		cv::Mat *imgptr = nullptr;
	}USTR;

	USTR mUstr;
	/*----------------------------function-------------------------------*/
public:
	//IO_op(void);
	~IO_op(void);

	IO_op(cv::Mat *ptr_img_);
	
	image_op_base_fi

};

#endif