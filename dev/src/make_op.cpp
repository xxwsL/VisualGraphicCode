#include "make_op.hpp"
 
ImageOpBase *make_op::ptrMake_op = nullptr;

make_op::MAKE_GUI make_op::mMake_GUI;

make_op::make_op(void) {
	init_GUI();

	connect(mMake_GUI.mImg_img_button, &QToolButton::clicked, [](){
		mMake_GUI.mImg_img_dialog->exec();
	});

	mMake_GUI.mSelect_layout->addWidget(mMake_GUI.mImg_img_button);

	mMake_GUI.mImg_img_dialog->setLayout(mMake_GUI.mImg_img_layout);
}

make_op::~make_op(void) {
	//delete mSelect_layout;

	//delete mImg_img_button;
	//delete mImg_img_widget;
	//delete mImg_img_layout;
}

QGridLayout* make_op::get_layout(const int32_t& flag_) {
	switch (flag_) {
	case ModelName::EM_ADD_TYPE::Add: {
		return mMake_GUI.mSelect_layout;
	}break;
	case ModelName::EM_IMG_IMG_TYPE::Gray: {
		return  mMake_GUI.mImg_img_layout;
	}break;
	default: {
		return mMake_GUI.mSelect_layout;
	}break;
	}
}

void make_op::load_creater(void) {
	
}

void make_op::init_GUI(void) {
	mMake_GUI.mSelect_layout = new QGridLayout;

	mMake_GUI.mImg_img_button = new BUTTON("img > img");
	mMake_GUI.mImg_img_dialog = new QDialog;
	mMake_GUI.mImg_img_dialog->setWindowTitle("img > img_model_list");
	mMake_GUI.mImg_img_layout = new QGridLayout;

	init_button();
}

void make_op::init_button(void) {
	BUTTON *mGray = new BUTTON("Gray");
	connect(mGray, &QToolButton::clicked, []() {
		ptrMake_op = Gray_op::create(0);
	});
	mMake_GUI.mImg_img_layout->addWidget(mGray);
}