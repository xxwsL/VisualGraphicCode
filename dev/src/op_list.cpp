#include "op_list.hpp"
#include "image_op_inc.hpp"

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
#ifdef XXWSL_DEBUG
		QMessageBox msgBox;
		msgBox.setText(tr("Error : OpList create fail"));
		msgBox.exec();
#endif
		exit(1);
	}
	mUstr.strFile_name = file_name_;

	mUstr.strListName = list_name_;

	mUstr.ptrGraph = new ListGraph(list_name_);

	add_model(new IO_op(imgSrc_));
	add_model(new AddOp(this, &ModelName::i32Mat_all, mUstr.vecTask.size(), mUstr.vecTask[0]->read_interface_ptr()));

}


void OpList::display_Copy(void) const {
	(*(mUstr.vecTask.end() - 2))->display();
}


void OpList::display_Src(void) const {
	if (mUstr.vecTask.empty()) {
#ifdef XXWSL_DEBUG
		QMessageBox msgBox;
		msgBox.setText(tr("Error : OpList->display_Src; prompt : vecTask is empty"));
		msgBox.exec();
#endif
		return;
	}
	else {
		mUstr.vecTask[0]->display();
	}
}

bool OpList::add_model(ImageOpBase *ptr_, const int & seq_) {
	if (!ptr_) {
#ifdef XXWSL_DEBUG
		QMessageBox msgBox;
		msgBox.setText(tr("Error : OpList->add_model parame : ImageOpBase *ptr_ is empty"));
		msgBox.exec();
#endif
		exit(1);
	}
	if (seq_ < 0 || seq_ >= (int)mUstr.vecTask.size()) {
		mUstr.vecTask.push_back(ptr_);
		mUstr.ptrGraph->add_button(mUstr.vecTask.back()->read_button_ptr());
	}
	else {
		mUstr.vecTask.insert(mUstr.vecTask.begin() + seq_, ptr_);
		mUstr.ptrGraph->add_button(mUstr.vecTask[seq_]->read_button_ptr(), seq_);
	}
	return true;
}

bool OpList::run(void) {
	for (size_t i = 0; i < mUstr.vecTask.size(); ++i) {
		mUstr.vecTask[i]->op();
	}
	if (mUstr.vecTask.size() == 2) {
		display_Copy();
	}
	else {
		cv::destroyAllWindows();
		(*(mUstr.vecTask.end() - 2))->display();
	}
	return true;
}


void OpList::display_graph(void) const {
	if (mUstr.ptrGraph) {
		mUstr.ptrGraph->show();
	}
}
