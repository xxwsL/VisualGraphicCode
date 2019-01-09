#pragma once
#ifndef _add_op_hpp_
#define _add_op_hpp_

#include "image_op_base.hpp"
#include "button.hpp"
#include "model_name.hpp"
#include "make_op.hpp"
#include "op_list.hpp"

#include <qwidget.h>
#include <qlayout.h>

#include <qwidget.h>
#include <qdialog.h>

#include <vector>
/*
ģ�����ģ��
*/
class AddOp : public QDialog, public ImageOpBase
{
	Q_OBJECT
	/*----------------------------data-------------------------------*/
public:

	/*
	siLoca_seq : ��ǰģ�鴦�ڶ��е�λ�����к�
	TYPE : ģ�������
	ptrBase_list : ���ڶ��е�ָ��
	pairInterface : �ӿ�
	*/
	typedef struct {
		int32_t* TYPE;
		std::string *strName;
		size_t siList_loca_seq = 0;
		OpList *ptrBase_list;
		INTERFACE::TEMPLATE pairInterface;
	}USTR;

	/*
	mLayout : ģ����沼��ָ��
	mButton ��ģ�鰴ť
	*/
	QLayout *mLayout = nullptr;
	BUTTON mButton;
	QDialog *mDialog = nullptr;

	USTR mUstr;
	/*----------------------------function-------------------------------*/
public:
	AddOp(void);
	~AddOp(void);
	/*
	ptr_base_list_ : �������е�ָ��
	type_ : ģ������
	seq_ ��ģ����������λ��
	interface_ ��ģ���м̽ӿ�
	*/
	AddOp(OpList *ptr_base_list_, int32_t* type_, size_t seq_, void* interface_);

	image_op_base_fi

private:
	/*
	���ò���
	ptr_base_list_ �����ڶ��ж����ָ��
	type_ : ģ������
	seq_ �����ڶ��е�λ��
	interface_ : �ӿ��м̿�
	*/
	inline void set(OpList *ptr_base_list_, int32_t* type_, \
		size_t seq_, void* interface_);

	/*
	����ģ������
	type_ ��ģ������
	*/
	void update_type(int32_t* type_);

	/*
	����ģ������
	type_left_ ����ڵ�ģ������
	type_right_ ���ҽڵ�ģ������
	*/
	void update_type(const int32_t& type_left_, const int32_t& type_right_);

private slots:
	void QT_show(void);
};
#endif