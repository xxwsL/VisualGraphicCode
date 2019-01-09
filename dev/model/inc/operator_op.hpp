#pragma once
#ifndef _binary_op_hpp_
#define _binary_op_hpp_

#include "image_op_base.hpp"

#include <qdialog.h>
#include <qslider.h>
#include <qlayout.h>
#include <qspinbox.h>

class Operator_big : public QDialog, public ImageOpBase
{
	Q_OBJECT
	/*----------------------------data-------------------------------*/
public:
	typedef struct{
		int32_t* TYPE;
		std::string *strName;
		INTERFACE::MAT_MAT mInterface;
		BUTTON mButton;

		double dValue;
		QSlider mSlider;
		QSpinBox mSpinBox;
		QHBoxLayout mLayout;
	}USTR;
	
	USTR mUstr;

	/*----------------------------function-------------------------------*/
public:
	Operator_big(void);
	~Operator_big(void);

	image_op_base_fi

private:
	void set_LineEdit_Value(const int& value_);
	
	void set_slider_Value(const int& value_);
};

class Operator_small : public ImageOpBase
{
	image_op_base_fi
};


#endif