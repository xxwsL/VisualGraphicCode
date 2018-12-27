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
		size_t siList_loca_seq = 0;
		std::pair<int32_t*, std::string*>  TYPE;
		OpList *ptrBase_list;
		ImageOpBase::INTERFACE_TEMPLATE pairInterface;
	}USTR;

	/*
	mLayout : ģ����沼��ָ��
	mButton ��ģ�鰴ť
	*/
	QGridLayout *mLayout = nullptr;
	BUTTON mButton;

	USTR mUstr;
	/*----------------------------function-------------------------------*/
public:
	AddOp(void);
	~AddOp(void);
	AddOp(OpList *ptr_base_list_, int32_t *ptr_int32_, std::string *ptr_str_, \
		size_t seq_, ImageOpBase::INTERFACE_TEMPLATE interface_);

	image_op_base_fi

	/*
	����һ������
	flag_ : ���ܱ�־λ(Ĭ��ֵ 0 : ����һ������,���ض���Ļ���ָ��, int32_t* : ��int32_t��ֵ��ǰģ�������ֵ)
	*/
	static ImageOpBase* create(int32_t *flag_ = 0);

private:
	/*
	���ò���
	ptr_base_list_ �����ڶ��ж����ָ��
	ptr_int32_ �� ����ֵ
	ptr_str_ �������ַ���
	seq_ �����ڶ��е�λ��
	*/
	inline void set(OpList *ptr_base_list_, int32_t *ptr_int32_, std::string *ptr_str_, \
		size_t seq_, ImageOpBase::INTERFACE_TEMPLATE interface_);

private slots:
	void QT_show(void);
};
#endif