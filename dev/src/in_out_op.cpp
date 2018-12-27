#include "in_out_op.hpp"

//IO_op::IO_op(void) {}

IO_op::~IO_op(void){

}

IO_op::IO_op(cv::Mat *ptr_img_) {
	mUstr.imgptr = ptr_img_;
	mUstr.TYPE.first = &ModelName::iIn;
	mUstr.TYPE.second = &ModelName::strIn;

	mButton.setText("in_image");
	mButton.setDisabled(true);
}

bool IO_op::op(void) {
	return true;
}

void IO_op::display(void) {

}

BUTTON* IO_op::read_button_ptr(void) {
	return &mButton;
}
void* IO_op::read_interface_ptr(void) {
	return mUstr.imgptr;
}

void IO_op::load_interface_ptr(void* interface_) {
	return;
}