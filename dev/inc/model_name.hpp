#pragma once
#ifndef _model_name_hpp_
#define _model_name_hpp_

#include <string>

#include <qlayout.h>

#ifndef ADD_TYPE 
#define ADD_TYPE 0
#endif 

#ifndef IMG_IMG_TYPE
#define IMG_IMG_TYPE ADD_TYPE+1
#endif

class ModelName{
	/*----------------------------data-------------------------------*/
public:
	typedef enum {
		Add = ADD_TYPE
	}EM_ADD_TYPE;

	typedef enum {
		Gray = IMG_IMG_TYPE,
	}EM_IMG_IMG_TYPE;

	static int iAdd;
	static std::string strAdd;

	static int iGray;
	static std::string strGray;
};

#endif
