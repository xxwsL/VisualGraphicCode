#pragma once
#ifndef _model_name_hpp_
#define _model_name_hpp_

#include <string>

#include <qlayout.h>

/*ģ�����ģ���*/
#ifndef ADD_TYPE 
#define ADD_TYPE 99
#endif 

/*img_imgģ���*/
#ifndef MAT_NAT_TYPE
#define MAT_ALL_TYPE 100
#endif

class ModelName{
	/*----------------------------data-------------------------------*/
public:

	//ģ�����ģ��flag
	typedef enum {
		In,
		Add = ADD_TYPE,
	}EM_ADD_TYPE;

	//mat_matģ��flag
	typedef enum {
		Mat_all = MAT_ALL_TYPE,
		Mat_mat,
	}EM_MAT_TYPE;

	//mat_all���ͱ�־
	static int32_t i32Mat_all;
	//mat_mat���ͱ�־
	static int32_t i32Mat_mat;

	//ģ�����ģ����������
	static std::string strAdd;

	//ģ��������������
	static std::string strIn;

	//Grayģ����������
	static std::string strGray;

	//operatorģ����������
	static std::string strOperator_big;
	static std::string strOperator_small;
};

#endif
