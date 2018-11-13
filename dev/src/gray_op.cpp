#include "gray_op.hpp"

Gray_op::Gray_op(void) {}

Gray_op::~Gray_op(void) {}

Gray_op::Gray_op(cv::Mat *ptrIn_, cv::Mat *ptrOut_) {
	if (ptrIn_->empty() || ptrOut_->empty()) {
		std::cout << "Error £» ptrImg_ is empty for Gray_op create\n";
		while (std::cin.get() != '\n');
		exit(1);
	}
	else {
		mUstr.imgIn = ptrIn_;
		mUstr.imgOut = ptrOut_;
	}
}

bool Gray_op::op(void *ustr_) const {
	cv::cvtColor(*mUstr.imgIn, *mUstr.imgOut, CV_BGR2GRAY);
	return true;
}