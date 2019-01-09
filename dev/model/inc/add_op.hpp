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
		int32_t* TYPE;
		std::string *strName;
		size_t siList_loca_seq = 0;
		OpList *ptrBase_list;
		INTERFACE::TEMPLATE pairInterface;
	}USTR;

	/*
	mLayout : 模块界面布局指针
	mButton ：模块按钮
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
	ptr_base_list_ : 所属队列的指针
	type_ : 模块类型
	seq_ ：模块所属队列位置
	interface_ ：模块中继接口
	*/
	AddOp(OpList *ptr_base_list_, int32_t* type_, size_t seq_, void* interface_);

	image_op_base_fi

private:
	/*
	设置参数
	ptr_base_list_ ：处于队列对象的指针
	type_ : 模块类型
	seq_ ：处于队列的位置
	interface_ : 接口中继口
	*/
	inline void set(OpList *ptr_base_list_, int32_t* type_, \
		size_t seq_, void* interface_);

	/*
	更新模块类型
	type_ ：模块类型
	*/
	void update_type(int32_t* type_);

	/*
	更新模块类型
	type_left_ ：左节点模块类型
	type_right_ ：右节点模块类型
	*/
	void update_type(const int32_t& type_left_, const int32_t& type_right_);

private slots:
	void QT_show(void);
};
#endif