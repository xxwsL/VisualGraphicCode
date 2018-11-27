#pragma once
#ifndef _image_op_base_hpp_
#define _image_op_base_hpp_

#include "image_op_base.hpp"
#include "button.hpp"

class ImageOpBase {
	/*----------------------------function-------------------------------*/
public:
	ImageOpBase(void) {};
	virtual ~ImageOpBase(void) {};

	virtual bool op(void) = 0;

	virtual void display(void) = 0;

	virtual BUTTON* read_button(void) = 0;

};

#endif