#include "gray_op.hpp"
#include "model_name.hpp"

Gray_op::Gray_op(void) {}

Gray_op::~Gray_op(void) {
	delete mUstr.mInterface.imgOut;
}

Gray_op::Gray_op(cv::Mat *ptrIn_) {
	if (ptrIn_->empty()) {
		std::cout << "Error £» ptrImg_ is empty for Gray_op create\n";
		while (std::cin.get() != '\n');
		exit(1);
	}
	else {
		mUstr.TYPE.first = &ModelName::iGray;
		mUstr.TYPE.second = &ModelName::strGray;
		mUstr.mButton.init_set(ModelName::strGray.c_str());

		mUstr.mInterface.imgIn = ptrIn_;
		mUstr.mInterface.imgOut = new cv::Mat;
	}
}

bool Gray_op::op(void) {
	cv::Mat img;
	cv::cvtColor(*mUstr.mInterface.imgIn, *mUstr.mInterface.imgOut, CV_BGR2GRAY);
	return true;
}

void Gray_op::display(void) {
	cv::imshow("Gray_image", *mUstr.mInterface.imgOut);
}

BUTTON* Gray_op::read_button_ptr(void) {
	return &mUstr.mButton;
}

void* Gray_op::read_interface_ptr(void) {
	return &mUstr.mInterface;
}

ImageOpBase* Gray_op::create(int32_t *flag_) {
	if (!flag_) {
		return new Gray_op;
	}
	else {
		*flag_ = ModelName::iGray;
		return nullptr;
	}
}