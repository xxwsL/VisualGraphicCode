#include "add_op.hpp"

AddOp::AddOp(std::vector<ImageOpBase*> *ptr_base_list_) : mButton(tr("+"))
{
	mUstr.ptrBase_list = ptr_base_list_;

	connect(&mButton, &QToolButton::clicked, this, &AddOp::QT_show);
	this->setLayout(mLayout);
}

AddOp::~AddOp(void){}



inline bool AddOp::op(void) {
	return true;
}

void AddOp::display(void) {
}

BUTTON* AddOp::read_button(void) {
	return &mButton;
}



inline void AddOp::set(int32_t *ptr_int32_, std::string *ptr_str_) {
	mUstr.TYPE.first = ptr_int32_;
	mUstr.TYPE.second = ptr_str_;
}



void AddOp::QT_show(void) {
	this->show();
}