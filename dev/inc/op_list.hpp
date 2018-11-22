#pragma once
#ifndef _op_list_hpp_
#define _op_list_hpp_

#include "image_op_inc.hpp"
#include "list_graph.hpp"

#include <opencv.hpp>

#include <vector>

class OpList {
	/*----------------------------data-------------------------------*/
public:
	typedef struct {
		cv::Mat imgCopy;
		std::vector<ImageOpBase*> vecTask;
		std::string strFile_name;
		ListGraph *ptrGraph = nullptr;
	}Ustr;

	Ustr mUstr;
	
protected:
	cv::Mat imgSrc;

	/*----------------------------function-------------------------------*/
public:
	//OpList(void);
	~OpList(void);

	OpList(const cv::Mat& imgSrc_, const std::string& file_name_);

	void display_Copy(void);

	void display_Src(void);

	bool add_model(ImageOpBase *ptr_, const int & seq_ = -1);

	bool run(void);

};

#endif