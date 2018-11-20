#include "op_list.hpp"

//OpList::OpList(void){}

OpList::~OpList(void) {
	for (size_t i = 0; i < mUstr.vecTask.size(); ++i) {
		delete mUstr.vecTask[i];
	}
	if (mUstr.ptrGraph != nullptr) {
		delete mUstr.ptrGraph;
	}
}

OpList::OpList(const cv::Mat& imgSrc_, const std::string& file_name_) {
	if (imgSrc_.empty()) {
		std::cout << ">> Error : OpList imgSrc is empty\n";
		while (std::cin.get() != '\n');
	}
	imgSrc_.copyTo(imgSrc);
	imgSrc_.copyTo(mUstr.imgCopy);
	mUstr.strFile_name = file_name_;

	mUstr.ptrGraph = nullptr;
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
	imgSrc.copyTo(mUstr.imgCopy);
	for (size_t i = 0; i < mUstr.vecTask.size(); ++i) {
		mUstr.vecTask[i]->op();
	}
	if (mUstr.vecTask.empty()) {
		display_Copy();
	}
	else {
		mUstr.vecTask.back()->display();
	}
	return true;
}

bool OpList::create_graph(void) {
	if (mUstr.ptrGraph == nullptr) {
		mUstr.ptrGraph = new ListGraph;
		return true;
	}
	else
	{
		return false;
	}
}