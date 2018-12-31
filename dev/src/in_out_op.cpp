#include "in_out_op.hpp"

//IO_op::IO_op(void) {}

IO_op::~IO_op(void){
	delete mUstr.mInterface.first;
	delete mUstr.mInterface.second;
}

IO_op::IO_op(const cv::Mat& ptr_img_) {
	mUstr.TYPE = &ModelName::i32Mat_mat;
	mUstr.strName = &ModelName::strIn;

	mUstr.mInterface.first = new cv::Mat;
	mUstr.mInterface.second = new cv::Mat;
	ptr_img_.copyTo(*mUstr.mInterface.first);
	ptr_img_.copyTo(*mUstr.mInterface.second);

	mUstr.mButton.setText("Mat");
	mUstr.mButton.setDisabled(true);
}

inline bool IO_op::op(void) {
	mUstr.mInterface.first->copyTo(*mUstr.mInterface.second);
	return true;
}

void IO_op::display(void) const {
	cv::imshow("SrcMat", *mUstr.mInterface.first);
}

BUTTON* IO_op::read_button_ptr(void) {
	return &mUstr.mButton;
}

void* IO_op::read_interface_ptr(void) {
	return mUstr.mInterface.second;
}

void IO_op::load_interface_ptr(void* interface_) {
	mUstr.mInterface.first = (cv::Mat*)interface_;
}

int32_t IO_op::read_i32_type(void) const {
	return *mUstr.TYPE;
}