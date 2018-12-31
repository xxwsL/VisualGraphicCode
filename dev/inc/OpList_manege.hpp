#pragma once
#ifndef _OpList_manege_hpp_
#define _OpList_manege_hpp_

#include "op_list.hpp"
#include "math_tool.hpp"
#include "make_op.hpp"

#include <vector>

#ifndef LIST_MAX
#define LIST_MAX 1
#endif

/*������й���ģ��*/
class OpListManege {
	/*----------------------------data-------------------------------*/
public:

	/*
	vecOpLists ����������
	siLoadList_label ����ǰʹ�ܶ��б��
	*/
	typedef struct {
		std::vector<OpList*> vecOpLists;
		int siLoadList_label = -1;
	}USTR;

	USTR mUstr;
	make_op mMaker;

	/*----------------------------function-------------------------------*/
public:
	OpListManege(void);
	~OpListManege(void);

	/*
	��������
	imgSrc_ ��ԭʼͼ��mat
	file_name_ ��ԭʼͼ����������
	list_name_ ����������
	*/
	bool create_Oplist(const cv::Mat& imgSrc_, const std::string& file_name_, const std::string& list_name_ = "");

	/*
	��ʾĳ���ڵ����
	seq_ ���ڵ���
	*/
	bool display_seq(const int& seq_ = -1);

	/*
	����ĳ����ŵĶ��е�����
	seq_ �����б�ţ�Ĭ�ϱ�� mUstr->siLoadList_label
	*/
	OpList& operator () (const int& seq_ = -1);

};

#endif
