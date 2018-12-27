#include "gray_op.hpp"
#include "model_name.hpp"
#include "make_op.hpp"

Gray_op::Gray_op(void) {
	mUstr.TYPE.first = &ModelName::iGray;
	mUstr.TYPE.second = &ModelName::strGray;
	mUstr.mButton.init_set(ModelName::strGray.c_str());

}

Gray_op::~Gray_op(void) {
	if (mUstr.mInterface.second) {
		delete mUstr.mInterface.second;
	}
}

bool Gray_op::op(void) {
	cv::cvtColor(*mUstr.mInterface.first, *mUstr.mInterface.second, CV_BGR2GRAY);
	return true;
}

void Gray_op::display(void) {
	cv::imshow("Gray_image", *mUstr.mInterface.second);
}

BUTTON* Gray_op::read_button_ptr(void) {
	return &mUstr.mButton;
}

void* Gray_op::read_interface_ptr(void) {
	return &mUstr.mInterface;
}

void Gray_op::load_interface_ptr(void* interface_) {
	mUstr.mInterface = *(ImageOpBase::IMG_IMG_INTERFACE*)interface_;
	set(mUstr.mInterface.first, mUstr.mInterface.second);
}

ImageOpBase* Gray_op::create(int32_t *flag_) {
	if (!flag_) {
		if (!make_op::ptrMake_op) {
			return new Gray_op;
		}
		else{
			return make_op::ptrMake_op;
		}
	}
	else {
		*flag_ = ModelName::iGray;
		return nullptr;
	}
}

void Gray_op::set(cv::Mat *ptrIn_, cv::Mat *ptrOut) {
	mUstr.mInterface.first = ptrIn_;
	if (ptrOut) {
		mUstr.mInterface.second = ptrOut;
	}
	else {
		mUstr.mInterface.second = new cv::Mat;
	}
}