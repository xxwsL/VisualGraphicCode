#pragma once
#ifndef _op_list_hpp_
#define _op_list_hpp_

#include "image_op_inc.hpp"
#include "list_graph.hpp"

#include <opencv.hpp>

#include <vector>

#include <qobject.h>
#include <qmessagebox.h>

class OpList : public QObject
{
	//Q_OBJECT
	/*----------------------------data-------------------------------*/
public:
	typedef struct {
		cv::Mat imgCopy;
		std::vector<ImageOpBase*> vecTask;
		std::string strFile_name;
		ListGraph *ptrGraph = nullptr;
		std::string strListName;
	}Ustr;

	Ustr mUstr;
	
protected:
	cv::Mat imgSrc;

	/*----------------------------function-------------------------------*/
public:
	//OpList(void);
	~OpList(void);

	OpList(const cv::Mat& imgSrc_, const std::string& file_name_, const std::string& list_name_);

	void display_Copy(void) const;

	void display_Src(void) const;

	bool add_model(ImageOpBase *ptr_, const int & seq_ = -1);

	bool run(void);

	void display_graph(void) const;

};

#endif