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
	if (mUstr.mInterface.first->channels() == 3) {
		cv::cvtColor(*mUstr.mInterface.first, *mUstr.mInterface.second, CV_BGR2GRAY);
		return true;
	}
	else {
		return false;
	}
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

void Gray_op::load_interface_ptr(void* interface_) {
	cv::Mat* ptrMat = (cv::Mat*)interface_;
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
	}
}

int32_t Gray_op::read_i32_type(void) const {
	return *mUstr.TYPE;
}