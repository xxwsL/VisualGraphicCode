#pragma once
#ifndef _image_op_base_hpp_
#define _image_op_base_hpp_

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
						 virtual void load_interface_ptr(void* ptrInterface_, void* ptrList_); \
						 virtual int32_t read_i32_type(void) const;
#endif

namespace INTERFACE {
	//mat_mat ģ��ӿ����ݽṹ
	typedef std::pair<cv::Mat*, cv::Mat*> MAT_MAT;

	//�ӿ�ģ��
	typedef std::pair<void*, void*> TEMPLATE;
};

/*
ͼ����ģ�����
*/
class ImageOpBase {
	/*----------------------------data-------------------------------*/
public:


	/*----------------------------function-------------------------------*/
public:
	ImageOpBase(void) {};
	virtual ~ImageOpBase(void) {};

	virtual bool op(void) = 0;

	virtual void display(void) const = 0;

	virtual BUTTON* read_button_ptr(void) = 0;

	virtual void* read_interface_ptr(void) = 0;

	virtual void load_interface_ptr(void* ptrInterface_, void* ptrList_) = 0;

	virtual int32_t read_i32_type(void) const = 0;

};

#endif