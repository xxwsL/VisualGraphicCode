#include "add_op.hpp"

AddOp::AddOp(void){}

AddOp::~AddOp(void){}

AddOp::AddOp(std::vector<ImageOpBase*> *ptr_base_list_, int32_t *ptr_int32_, std::string *ptr_str_) : mButton(tr("+"))
{
	connect(&mButton, &QToolButton::clicked, this, &AddOp::QT_show);
	set(ptr_base_list_, ptr_int32_, ptr_str_);
}

inline bool AddOp::op(void) {
	return true;
}

void AddOp::display(void) {
}

BUTTON* AddOp::read_button(void) {
	return &mButton;
}

ImageOpBase* AddOp::create(int32_t *flag_) {
	if (!flag_) {
		return new AddOp;
	}
	else {
		*flag_ = ModelName::iAdd;
		return nullptr;
	}
}

inline void AddOp::set(std::vector<ImageOpBase*> *ptr_base_list_, int32_t *ptr_int32_, std::string *ptr_str_) {
	mUstr.ptrBase_list = ptr_base_list_;
	mUstr.TYPE.first = ptr_int32_;
	mUstr.TYPE.second = ptr_str_;
	this->setLayout(make_op::get_layout(*ptr_int32_));
}



void AddOp::QT_show(void) {
	this->exec();
}