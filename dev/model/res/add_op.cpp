#include "add_op.hpp"

AddOp::AddOp(void){}

AddOp::~AddOp(void){

}

AddOp::AddOp(int32_t* type_, void* interface_, OpList *ptr_base_list_, size_t seq_) : mButton(tr("+"))
{
	mUstr.strName = &ModelName::strAdd;
	mUstr.pairInterface.first = nullptr;
	mUstr.pairInterface.second = nullptr;
	connect(&mButton, &QToolButton::clicked, this, &AddOp::QT_show);
	set(type_, interface_, ptr_base_list_, seq_);
}

inline bool AddOp::op(void) {
	return true;
}

void AddOp::display(void) const{
}

BUTTON* AddOp::read_button_ptr(void) {
	return &mButton;
}

void* AddOp::read_interface_ptr(void) {
	return mUstr.pairInterface.first;
}

void AddOp::load_interface_ptr(void* ptrInterface_, void* ptrList_) {
	mUstr.pairInterface.first = ptrInterface_;
	mUstr.ptrBase_list = (OpList*)ptrList_;
}

int32_t AddOp::read_i32_type(void) const {
	return *mUstr.TYPE;
}

inline void AddOp::set(int32_t* type_, void* interface_, OpList *ptr_base_list_, size_t seq_) {

	mUstr.TYPE = type_;
	load_interface_ptr(interface_, ptr_base_list_);
	update_type(type_);
	mUstr.siList_loca_seq = seq_;
}

void AddOp::update_type(int32_t* type_) {
	mUstr.TYPE = type_;
	mDialog = make_op::read_dialog_ptr(*mUstr.TYPE);
	
}

void AddOp::update_type(const int32_t& type_left, const int32_t& type_right_) {
	mUstr.TYPE = make_op::switch_type(type_left, type_right_);
	mDialog = make_op::read_dialog_ptr(*mUstr.TYPE);
	
}

void AddOp::QT_show(void) {

	mDialog->exec();

	if (make_op::ptrMake_op != nullptr) {

		int32_t i32Right_flag = NULL;

		//生成的模块装载接口
		make_op::ptrMake_op->load_interface_ptr(mUstr.pairInterface.first, mUstr.ptrBase_list);

		//如有有当前节点不是末尾节点，下一节点装载接口
		ImageOpBase *PtrOp = nullptr;
		if (mUstr.siList_loca_seq < mUstr.ptrBase_list->mUstr.vecTask.size() - 1) {
			PtrOp = mUstr.ptrBase_list->mUstr.vecTask[mUstr.siList_loca_seq + 1];
			PtrOp->load_interface_ptr(make_op::ptrMake_op->read_interface_ptr(), mUstr.ptrBase_list);
			i32Right_flag = PtrOp->read_i32_type();
		}

		//更新当前节点类型
		update_type(*mUstr.TYPE, make_op::ptrCreate_flag);
		//生成一个添加模块
		ImageOpBase *ptrTp = new AddOp(make_op::switch_type(make_op::ptrCreate_flag, i32Right_flag), \
			make_op::ptrMake_op->read_interface_ptr(), mUstr.ptrBase_list, mUstr.siList_loca_seq + 2);

		//添加生成的模块到队列中去
		mUstr.ptrBase_list->add_model(make_op::ptrMake_op, (int)mUstr.siList_loca_seq + 1);
		mUstr.ptrBase_list->add_model(ptrTp, (int)mUstr.siList_loca_seq + 2);

		make_op::ptrMake_op = nullptr;
		make_op::ptrCreate_flag = NULL;

		cv::destroyAllWindows();
		mUstr.ptrBase_list->run();
	}
}