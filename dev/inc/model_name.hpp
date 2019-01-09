#pragma once
#ifndef _model_name_hpp_
#define _model_name_hpp_

#include <string>

#include <qlayout.h>

/*模块添加模块宏*/
#ifndef ADD_TYPE 
#define ADD_TYPE 99
#endif 

/*img_img模块宏*/
#ifndef MAT_NAT_TYPE
#define MAT_ALL_TYPE 100
#endif

class ModelName{
	/*----------------------------data-------------------------------*/
public:

	//模块添加模块flag
	typedef enum {
		In,
		Add = ADD_TYPE,
	}EM_ADD_TYPE;

	//mat_mat模块flag
	typedef enum {
		Mat_all = MAT_ALL_TYPE,
		Mat_mat,
	}EM_MAT_TYPE;

	//mat_all类型标志
	static int32_t i32Mat_all;
	//mat_mat类型标志
	static int32_t i32Mat_mat;

	//模块添加模块类型数据
	static std::string strAdd;

	//模块输入数据类型
	static std::string strIn;

	//Gray模块类型数据
	static std::string strGray;

	//operator模块类型数据
	static std::string strOperator_big;
	static std::string strOperator_small;
};

#endif
