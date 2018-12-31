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

/*处理队列管理模块*/
class OpListManege {
	/*----------------------------data-------------------------------*/
public:

	/*
	vecOpLists ：队列容器
	siLoadList_label ：当前使能队列编号
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
	创建队列
	imgSrc_ ：原始图像mat
	file_name_ ：原始图像完整名字
	list_name_ ：队列名字
	*/
	bool create_Oplist(const cv::Mat& imgSrc_, const std::string& file_name_, const std::string& list_name_ = "");

	/*
	显示某个节点输出
	seq_ ：节点编号
	*/
	bool display_seq(const int& seq_ = -1);

	/*
	返回某个编号的队列的引用
	seq_ ：队列编号，默认编号 mUstr->siLoadList_label
	*/
	OpList& operator () (const int& seq_ = -1);

};

#endif
