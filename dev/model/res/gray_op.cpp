#include "gray_op.hpp"
#include "model_name.hpp"
#include "make_op.hpp"
#include "xxwsL_debug.hpp"

Gray_op::Gray_op(void) {
	mUstr.TYPE = &ModelName::i32Mat_mat;
	mUstr.strName = &ModelName::strGray;
	mUstr.mButton.init_set(ModelName::strGray.c_str());
	mUstr.mInterface.first = nullptr;
	mUstr.mInterface.second = nullptr;
}

Gray_op::~Gray_op(void) {
	if (mUstr.mInterface.second) {
		delete mUstr.mInterface.second;
	}
}

bool Gray_op::op(void) {
	switch (mUstr.mInterface.first->channels()) {
	case 1: {
		mUstr.mInterface.first->copyTo(*mUstr.mInterface.second);
	}break;
	case 3: {
		cv::cvtColor(*mUstr.mInterface.first, *mUstr.mInterface.second, CV_BGR2GRAY);
	}break;
	default: {
#ifdef XXWSL_DEBUG
		QMessageBox msgBox;
		msgBox.setText("Error : Gray_op->op : input data channels is uncode");
		msgBox.exec();
#endif
		exit(1);
	}break;
	}
	return true;
}

void Gray_op::display(void) const {
	cv::imshow("Gray_image", *mUstr.mInterface.second);
}

BUTTON* Gray_op::read_button_ptr(void) {
	return &mUstr.mButton;
}

void* Gray_op::read_interface_ptr(void) {
	return mUstr.mInterface.second;
}

void Gray_op::load_interface_ptr(void* ptrInterface_, void* ptrList_) {
	cv::Mat* ptrMat = (cv::Mat*)ptrInterface_;
	if (ptrMat->empty()) {
#ifdef XXWSL_DEBUG
		QMessageBox msgBox;
		msgBox.setText("Error : Gray_op->load_interface_ptr : parame interface_ is empty");
		msgBox.exec();
#endif
		exit(1);
	}
	else {
		mUstr.mInterface.first = ptrMat;
		mUstr.mInterface.second = new cv::Mat;
		ptrMat->copyTo(*mUstr.mInterface.second);
		mUstr.ptrBase_list = (OpList*)ptrList_;
	}
}

int32_t Gray_op::read_i32_type(void) const {
	return *mUstr.TYPE;
}