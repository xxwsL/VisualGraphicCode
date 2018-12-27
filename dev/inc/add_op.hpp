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
模块添加模块
*/
class AddOp : public QDialog, public ImageOpBase
{
	Q_OBJECT
	/*----------------------------data-------------------------------*/
public:

	/*
	siLoca_seq : 当前模块处于队列的位置序列号
	TYPE : 模块的类型
	ptrBase_list : 处于队列的指针
	pairInterface : 接口
	*/
	typedef struct {
		size_t siList_loca_seq = 0;
		std::pair<int32_t*, std::string*>  TYPE;
		OpList *ptrBase_list;
		ImageOpBase::INTERFACE_TEMPLATE pairInterface;
	}USTR;

	/*
	mLayout : 模块界面布局指针
	mButton ：模块按钮
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
	创建一个对象
	flag_ : 功能标志位(默认值 0 : 创建一个对象,返回对象的基类指针, int32_t* : 将int32_t赋值当前模块的类型值)
	*/
	static ImageOpBase* create(int32_t *flag_ = 0);

private:
	/*
	设置参数
	ptr_base_list_ ：处于队列对象的指针
	ptr_int32_ ： 类型值
	ptr_str_ ：类型字符串
	seq_ ：处于队列的位置
	*/
	inline void set(OpList *ptr_base_list_, int32_t *ptr_int32_, std::string *ptr_str_, \
		size_t seq_, ImageOpBase::INTERFACE_TEMPLATE interface_);

private slots:
	void QT_show(void);
};
#endif