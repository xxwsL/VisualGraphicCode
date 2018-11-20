#pragma once
#ifndef _image_op_base_hpp_
#define _image_op_base_hpp_

#include "image_op_base.hpp"

class ImageOpBase {
	/*----------------------------function-------------------------------*/
public:
	ImageOpBase(void) {};
	virtual ~ImageOpBase(void) {};

	virtual bool op(void) = 0;

	virtual bool display() = 0;
};

#endif