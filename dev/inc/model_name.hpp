#pragma once
#ifndef _model_name_hpp_
#define _model_name_hpp_

#include <string>

#include <qlayout.h>

/*模块添加模块宏*/
#ifndef ADD_TYPE 
#define ADD_TYPE_ALL 0
#endif 

/*img_img模块宏*/
#ifndef IMG_IMG_TYPE
#define IMG_IMG_TYPE ADD_TYPE_ALL + 1
#endif

class ModelName{
	/*----------------------------data-------------------------------*/
public:
	//模块添加模块flag
	typedef enum {
		Add = ADD_TYPE_ALL
	}EM_ADD_TYPE;

	//img_img模块flag
	typedef enum {
		Gray = IMG_IMG_TYPE,
	}EM_IMG_IMG_TYPE;

	//模块添加模块类型数据
	static int32_t iAdd;
	static std::string strAdd;

	//img_img模块类型数据
	static int32_t iGray;
	static std::string strGray;
};

#endif
