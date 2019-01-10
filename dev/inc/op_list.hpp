#pragma once
#ifndef _op_list_hpp_
#define _op_list_hpp_

#include "list_graph.hpp"
#include "image_op_base.hpp"

#include <opencv.hpp>

#include <vector>

#include <qobject.h>
#include <qmessagebox.h>

/*
������ж���
*/
class OpList : public QObject
{
	//Q_OBJECT
	/*----------------------------data-------------------------------*/
public:
	/*
	imgCopy ����������ͼ����
	vecTask �����д���ģ������
	strFile_name �� ԭʼͼ������
	ptrGraph �� ���п��ӻ��������
	strListName ����������
	*/
	typedef struct {
		cv::Mat imgCopy;
		std::vector<ImageOpBase*> vecTask;
		std::string strFile_name;
		ListGraph *ptrGraph = nullptr;
		std::string strListName;
	}Ustr;

	Ustr mUstr;
	
protected:

	/*----------------------------function-------------------------------*/
public:
	//OpList(void);
	~OpList(void);

	OpList(const cv::Mat& imgSrc_, const std::string& file_name_, const std::string& list_name_);

	/*
	��ʾ����ͼ��
	*/
	void display_Copy(void) const;

	/*
	��ʾԭʼͼ��
	*/
	void display_Src(void) const;

	/*
	���ģ��
	ptr_ ����ģ��ָ��
	seq_ ����ģ�����λ��
	*/
	bool add_model(ImageOpBase *ptr_, const int & seq_ = -1);

	/*
	���д�������
	*/
	bool run(const size_t& seq_ = 0);

	/*
	��ʾ�������̽���
	*/
	void display_graph(void) const;

};

#endif