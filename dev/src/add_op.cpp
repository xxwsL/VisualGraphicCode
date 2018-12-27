#include "add_op.hpp"

AddOp::AddOp(void){}

AddOp::~AddOp(void){}

AddOp::AddOp(OpList *ptr_base_list_, int32_t *ptr_int32_, std::string *ptr_str_, 
	size_t seq_, ImageOpBase::INTERFACE_TEMPLATE interface_) : mButton(tr("+"))
{
	connect(&mButton, &QToolButton::clicked, this, &AddOp::QT_show);
	set(ptr_base_list_, ptr_int32_, ptr_str_, seq_, interface_);
}

inline bool AddOp::op(void) {
	return true;
}

void AddOp::display(void) {}

BUTTON* AddOp::read_button_ptr(void) {
	return &mButton;
}

void* AddOp::read_interface_ptr(void) {
	return nullptr;
}

void AddOp::load_interface_ptr(void* ptrInterface_) {
	mUstr.pairInterface = *(ImageOpBase::INTERFACE_TEMPLATE*)ptrInterface_;
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

inline void AddOp::set(OpList *ptr_base_list_, int32_t *ptr_int32_, std::string *ptr_str_, \
	size_t seq_, ImageOpBase::INTERFACE_TEMPLATE interface_) {

	mUstr.ptrBase_list = ptr_base_list_;
	mUstr.TYPE.first = ptr_int32_;
	mUstr.TYPE.second = ptr_str_;
	mUstr.siList_loca_seq = seq_;
	load_interface_ptr(&interface_);
	this->setLayout(make_op::read_layout_ptr(*ptr_int32_));
}

void AddOp::QT_show(void) {
	this->exec();
	if (make_op::ptrMake_op != nullptr) {
		make_op::ptrMake_op->load_interface_ptr(&mUstr.pairInterface);
		mUstr.ptrBase_list->add_model(make_op::ptrMake_op, (int)mUstr.siList_loca_seq + 1);
		ImageOpBase *ptrTp = new AddOp(mUstr.ptrBase_list, &ModelName::iAdd, &ModelName::strAdd, mUstr.siList_loca_seq + 2, \
		std::make_pair(nullptr, nullptr));
		mUstr.ptrBase_list->add_model(ptrTp, (int)mUstr.siList_loca_seq + 2);
		make_op::ptrMake_op = nullptr;
		make_op::ptrCreate_flag = NULL;
	}
}