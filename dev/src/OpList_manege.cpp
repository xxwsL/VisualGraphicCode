#include "OpList_manege.hpp"

OpListManege::OpListManege(void){}

OpListManege::~OpListManege(void) {
	for (size_t i = 0; i < mUstr.vecOpLists.size(); ++i) {
		delete  mUstr.vecOpLists[i];
	}
}

/*
>>����һ���������
imgSrc_ : ����ԭʼͼ��file_name_ : ԭʼͼ������
*/
bool OpListManege::create_Oplist(const cv::Mat& imgSrc_, const std::string& file_name_) {
	if (mUstr.vecOpLists.size() < LIST_MAX) {
		mUstr.vecOpLists.push_back(new OpList(imgSrc_, file_name_));
		mUstr.siLoadList_label = (int)mUstr.vecOpLists.size() - 1;
		return true;
	}
	else {
		return false;
	}
}

bool OpListManege::display_seq(const int& seq_) {
	if (mUstr.siLoadList_label == -1) {
		return false;
	}
	else if (seq_ < 0 || seq_ >= mUstr.vecOpLists.size()) {
		mUstr.vecOpLists.back()->display_Copy();
	}
	else {
		mUstr.vecOpLists[seq_]->display_Copy();
	}
	return true;
}


OpList& OpListManege::operator () (const int& seq_) {
	if (seq_ < 0) {
		return *mUstr.vecOpLists[mUstr.siLoadList_label];
	}
	else {
		return *mUstr.vecOpLists[seq_];
	}
}