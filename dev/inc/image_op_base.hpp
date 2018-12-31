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
						 virtual void display(void) const; \
						 virtual BUTTON* read_button_ptr(void); \
						 virtual void* read_interface_ptr(void); \
						 virtual void load_interface_ptr(void* ptrInterface_); \
						 virtual int32_t read_i32_type(void) const;
#endif

/*
ͼ����ģ�����
*/
class ImageOpBase {
	/*----------------------------data-------------------------------*/
public:
	//img_img ģ��ӿ����ݽṹ
	typedef std::pair<cv::Mat*, cv::Mat*> IMG_IMG_INTERFACE;

	//�ӿ�ģ��
	typedef std::pair<void*, void*> INTERFACE_TEMPLATE;

	/*----------------------------function-------------------------------*/
public:
	ImageOpBase(void) {};
	virtual ~ImageOpBase(void) {};

	virtual bool op(void) = 0;

	virtual void display(void) const = 0;

	virtual BUTTON* read_button_ptr(void) = 0;

	virtual void* read_interface_ptr(void) = 0;

	virtual void load_interface_ptr(void* ptrInterface_) = 0;

	virtual int32_t read_i32_type(void) const = 0;

};

#endif