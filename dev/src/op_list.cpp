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

OpList::OpList(const cv::Mat& imgSrc_, const std::string& file_name_, const std::string& list_name_) {
	if (imgSrc_.empty()) {
		QMessageBox msgBox;
		msgBox.setText(tr("Error : OpList create fail"));
		msgBox.exec();
		exit(1);
	}
	imgSrc_.copyTo(imgSrc);
	imgSrc_.copyTo(mUstr.imgCopy);
	mUstr.strFile_name = file_name_;

	mUstr.strListName = list_name_;

	mUstr.ptrGraph = new ListGraph(list_name_);

	mUstr.vecTask.push_back(new AddOp(&mUstr.vecTask, &ModelName::iAdd, &ModelName::strAdd));
	mUstr.ptrGraph->add_button(mUstr.vecTask[0]->read_button_ptr());

}


void OpList::display_Copy(void) const {
	cv::imshow("imgCopy", mUstr.imgCopy);
}


void OpList::display_Src(void) const {
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


void OpList::display_graph(void) const {
	if (mUstr.ptrGraph) {
		mUstr.ptrGraph->show();
	}
}
