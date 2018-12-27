#include "make_op.hpp"
 
ImageOpBase *make_op::ptrMake_op = nullptr;
int32_t make_op::ptrCreate_flag = NULL;

make_op::MAKE_GUI make_op::mMake_GUI;

make_op::make_op(void) {
	//初始化GUI
	init_GUI();

	//连接img_img模块生成dialog
	connect(mMake_GUI.mImg_img_button, &QToolButton::clicked, [](){
		mMake_GUI.mImg_img_dialog->exec();
	});
	//img_img模块生成dialog设置布局
	mMake_GUI.mImg_img_dialog->setLayout(mMake_GUI.mImg_img_layout);

	//all模块生成布局添加img_img按钮部件
	mMake_GUI.mSelect_layout->addWidget(mMake_GUI.mImg_img_button);
}

make_op::~make_op(void) {
	//delete mSelect_layout;

	//delete mImg_img_button;
	//delete mImg_img_widget;
	//delete mImg_img_layout;
}

/*
>> 读取布局指针
flag_ : 读取布局的类型
*/
QGridLayout* make_op::read_layout_ptr(const int32_t& flag_) {
	switch (flag_) {
	case ModelName::EM_ADD_TYPE::Add: {
		return mMake_GUI.mSelect_layout;
	}break;
	case ModelName::EM_IMG_IMG_TYPE::Img_img: {
		return  mMake_GUI.mImg_img_layout;
	}break;
	default: {
		return mMake_GUI.mSelect_layout;
	}break;
	}
}

/*
>> 初始化GUI
*/
void make_op::init_GUI(void) {
	mMake_GUI.mSelect_layout = new QGridLayout;

	//img_img模块GUI部分
	mMake_GUI.mImg_img_button = new BUTTON("img > img");
	mMake_GUI.mImg_img_dialog = new QDialog;
	mMake_GUI.mImg_img_dialog->setWindowTitle("img > img_model_list");
	mMake_GUI.mImg_img_layout = new QGridLayout;

	//初始化button
	init_button();
}

/*
>> 初始化button
*/
void make_op::init_button(void) {
	//初始化 Gray 模块
	BUTTON *mGray = new BUTTON("Gray");
	connect(mGray, &QToolButton::clicked, []() {
		ptrMake_op = Gray_op::create(nullptr);
		ptrCreate_flag = ModelName::iGray;
	});
	mMake_GUI.mImg_img_layout->addWidget(mGray);
}