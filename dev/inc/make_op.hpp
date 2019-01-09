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
		//mat->all���沼��
		QGridLayout *ptrMat_all_layout = nullptr;
		//mat->all����
		QDialog *ptrMat_all_dialog = nullptr;

		//mat->all��mat->mat��ť
		BUTTON *ptrMat_mat_button = nullptr;
		//mat->mat����
		QGridLayout *ptrMat_mat_layout_0 = nullptr;
		//mat->all��mat->mat����
		QGridLayout *ptrMat_mat_layout_1 = nullptr;
		//mat->mat�Ľ���
		QDialog *mMat_mat_dialog_0 = nullptr;
		//mat->all��mat->mat�Ľ���
		QDialog *mMat_mat_dialog_1 = nullptr;
		
	}MAKE_GUI;

	typedef struct {
		//Grayģ�鰴ť
		BUTTON *mGray_0 = nullptr;
		BUTTON *mGray_1 = nullptr;

		//Operator_bigģ�鰴ť
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
	�ر�
	*/
	void close(void);

	/*
	��ȡ����ָ��
	type_flag_ ������flag
	*/
	static QLayout* make_op::read_layout_ptr(const int32_t& flag_);
	static QDialog* make_op::read_dialog_ptr(const int32_t& flag_);

	/*
	�ж�ѡ������
	i32Left ����ڵ�����
	i32Right ���нڵ�����
	*/
	static int32_t* switch_type(const int32_t& i32Left, const int32_t& i32Right);

private:
	/*
	��ʼ��GUI
	*/
	static void init_GUI(void);

	/*
	��ʼ����ť
	*/
	static void init_button(void);

};

#endif