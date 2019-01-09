#pragma once
#ifndef _make_op_hpp_
#define _make_op_gpp_

#include "image_op_inc.hpp"
#include "model_name.hpp"

#include <qlayout.h>
#include <qdialog.h>

#include <vector>

#ifndef MODEL_LIST_NAME
#define MODEL_LIST_NAME
#define MAT_ALL_STR QString("mat->all")
#define MAT_MAT_STR QString("mat->mat")
#endif

class make_op : QObject{
	Q_OBJECT

	/*----------------------------data-------------------------------*/
public:
	static ImageOpBase *ptrMake_op;
	static int32_t ptrCreate_flag;

public:

	typedef struct {
		//mat->all界面布局
		QGridLayout *ptrMat_all_layout = nullptr;
		//mat->all界面
		QDialog *ptrMat_all_dialog = nullptr;

		//mat->all的mat->mat按钮
		BUTTON *ptrMat_mat_button = nullptr;
		//mat->mat布局
		QGridLayout *ptrMat_mat_layout_0 = nullptr;
		//mat->all的mat->mat布局
		QGridLayout *ptrMat_mat_layout_1 = nullptr;
		//mat->mat的界面
		QDialog *mMat_mat_dialog_0 = nullptr;
		//mat->all的mat->mat的界面
		QDialog *mMat_mat_dialog_1 = nullptr;
		
	}MAKE_GUI;

	typedef struct {
		//Gray模块按钮
		BUTTON *mGray_0 = nullptr;
		BUTTON *mGray_1 = nullptr;

		//Operator_big模块按钮
		BUTTON *Operator_big_0 = nullptr;
		BUTTON *Operator_big_1 = nullptr;

	}MODEL_BUTTON;

	static MAKE_GUI mMake_GUI;
	static MODEL_BUTTON mMake_button;

	/*----------------------------function-------------------------------*/
public:
	make_op(void);

	~make_op(void);

	/*
	关闭
	*/
	void close(void);

	/*
	读取布局指针
	type_flag_ ：类型flag
	*/
	static QLayout* make_op::read_layout_ptr(const int32_t& flag_);
	static QDialog* make_op::read_dialog_ptr(const int32_t& flag_);

	/*
	判断选择类型
	i32Left ：左节点类型
	i32Right ：有节点类型
	*/
	static int32_t* switch_type(const int32_t& i32Left, const int32_t& i32Right);

private:
	/*
	初始化GUI
	*/
	static void init_GUI(void);

	/*
	初始化按钮
	*/
	static void init_button(void);

};

#endif