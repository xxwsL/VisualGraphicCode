#include "gray_op.hpp"
#include "model_name.hpp"

Gray_op::Gray_op(void) {}

Gray_op::~Gray_op(void) {}

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

		mUstr.imgIn = ptrIn_;
	}
}

bool Gray_op::op(void) {
	cv::Mat img;
	cv::cvtColor(*mUstr.imgIn, mUstr.imgOut, CV_BGR2GRAY);
	return true;
}

void Gray_op::display(void) {
	cv::imshow("Gray_image", mUstr.imgOut);
}

BUTTON* Gray_op::read_button(void) {
	return &mUstr.mButton;
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