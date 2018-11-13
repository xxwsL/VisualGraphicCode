#include "op_list.hpp"

OpList::OpList(void){}

OpList::~OpList(void) {
	for (size_t i = 0; i < mUstr.vecTask.size(); ++i) {
		delete mUstr.vecTask[i];
	}
}

OpList::OpList(const cv::Mat& imgSrc_, const std::string& file_name_) {
	imgSrc_.copyTo(imgSrc);
	imgSrc_.copyTo(mUstr.imgCopy);
	mUstr.strFile_name = file_name_;
}


void OpList::display_Copy(void) {
	cv::imshow("imgCopy", mUstr.imgCopy);
}


void OpList::display_Src(void) {
	cv::imshow(mUstr.strFile_name, imgSrc);
}

bool OpList::add_model(ImageOpBase *ptr_, const int & seq_) {
	if (seq_ > (int)mUstr.vecTask.size()) {
		return false;
	}
	else if(seq_ < 0){
		mUstr.vecTask.push_back(ptr_);
	}
	else {
		mUstr.vecTask.insert(mUstr.vecTask.begin() + seq_, ptr_);
	}
	return true;
}

bool OpList::run(void) {
	for (size_t i = 0; i < mUstr.vecTask.size(); ++i) {
		mUstr.vecTask[i]->op(0);
	}
	return true;
}