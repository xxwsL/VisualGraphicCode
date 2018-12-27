#pragma once
#ifndef _image_op_base_hpp_
#define _image_op_base_hpp_

#include "image_op_base.hpp"
#include "button.hpp"

#include <opencv.hpp>

/*
接口函数
op ：处理功能运行
display : 显示或打印输出
reda_button_ptr : 读取按键对象指针
read_intreface_ptr : 读取接口指针
*/
#ifndef image_op_base_fi
#define image_op_base_fi virtual bool op(void); \
						 virtual void display(void); \
						 virtual BUTTON* read_button_ptr(void); \
						 virtual void* read_interface_ptr(void); \
						 virtual void load_interface_ptr(void* ptrInterface_); 
#endif

/*
图像处理模块基类
*/
class ImageOpBase {
	/*----------------------------data-------------------------------*/
public:
	//img_img 模块接口数据结构
	typedef std::pair<cv::Mat*, cv::Mat*> IMG_IMG_INTERFACE;

	//接口属性
	typedef enum {
		left = 0,
		right,
	}INTERFACE_ATTRIBUTE;

	//接口模板
	typedef std::pair<void*, void*> INTERFACE_TEMPLATE;


	/*----------------------------function-------------------------------*/
public:
	ImageOpBase(void) {};
	virtual ~ImageOpBase(void) {};

	virtual bool op(void) = 0;

	virtual void display(void) = 0;

	virtual BUTTON* read_button_ptr(void) = 0;

	virtual void* read_interface_ptr(void) = 0;

	virtual void load_interface_ptr(void* ptrInterface_) = 0;

};

#endif