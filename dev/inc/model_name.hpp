#pragma once
#ifndef _model_name_hpp_
#define _model_name_hpp_

#include <string>

#include <qlayout.h>

/*ģ�����ģ���*/
#ifndef ADD_TYPE 
#define ADD_TYPE_ALL 100
#endif 

/*img_imgģ���*/
#ifndef IMG_IMG_TYPE
#define IMG_IMG_TYPE ADD_TYPE_ALL + 1
#endif

class ModelName{
	/*----------------------------data-------------------------------*/
public:
	//ģ�����ģ��flag
	typedef enum {
		In,
		Add = ADD_TYPE_ALL,
	}EM_ADD_TYPE;

	//img_imgģ��flag
	typedef enum {
		Img_img = IMG_IMG_TYPE,
		Gray,
	}EM_IMG_IMG_TYPE;

	//ģ�����ģ����������
	static int32_t iAdd;
	static std::string strAdd;

	static int32_t iIn;
	static std::string strIn;

	//img_imgģ����������
	static int32_t iGray;
	static std::string strGray;
};

#endif
