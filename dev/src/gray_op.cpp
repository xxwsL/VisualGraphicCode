#include "gray_op.hpp"
#include "model_name.hpp"

//Gray_op::Gray_op(void) {}

Gray_op::~Gray_op(void) {}

Gray_op::Gray_op(cv::Mat *ptrIn_) {
	if (ptrIn_->empty()) {
		std::cout << "Error �� ptrImg_ is empty for Gray_op create\n";
		while (std::cin.get() != '\n');
		exit(1);
	}
	else {
		mUstr.TYPE = ModelName::Gray;
		mUstr.imgIn = ptrIn_;
	}
}

bool Gray_op::op(void) {
	cv::Mat img;
	cv::cvtColor(*mUstr.imgIn, mUstr.imgOut, CV_BGR2GRAY);
	return true;
}

bool Gray_op::display(void) {
	cv::imshow("Gray_image", mUstr.imgOut);
	return true;
}