#pragma once
#ifndef _image_op_base_hpp_
#define _image_op_base_hpp_

#include "image_op_base.hpp"
#include "button.hpp"

#include <opencv.hpp>

/*
�ӿں���
op ������������
display : ��ʾ���ӡ���
reda_button_ptr : ��ȡ��������ָ��
read_intreface_ptr : ��ȡ�ӿ�ָ��
*/
#ifndef image_op_base_fi
#define image_op_base_fi virtual bool op(void); \
						 virtual void display(void); \
						 virtual BUTTON* read_button_ptr(void); \
						 virtual void* read_interface_ptr(void);
#endif

/*
ͼ����ģ�����
*/
class ImageOpBase {
	/*----------------------------data-------------------------------*/
public:
	//img_img ģ��ӿ����ݽṹ
	typedef struct {
		cv::Mat *imgIn = nullptr;
		cv::Mat *imgOut = nullptr;
	}IMG_IMG_INTERFACE;

	/*----------------------------function-------------------------------*/
public:
	ImageOpBase(void) {};
	virtual ~ImageOpBase(void) {};

	virtual bool op(void) = 0;

	virtual void display(void) = 0;

	virtual BUTTON* read_button_ptr(void) = 0;

	virtual void* read_interface_ptr(void) = 0;

};

#endif