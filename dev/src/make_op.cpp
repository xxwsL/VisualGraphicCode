#include "make_op.hpp"
 
ImageOpBase *make_op::ptrMake_op = nullptr;

QGridLayout *make_op::mSelect_layout = nullptr;

BUTTON *make_op::mImg_img_button = nullptr;
QDialog *make_op::mImg_img_widget = nullptr;
QGridLayout *make_op::mImg_img_layout = nullptr;

make_op::make_op(void) {
	init_variable();

	connect(mImg_img_button, &QToolButton::clicked, [](){
		mImg_img_widget->exec();
	});

	mSelect_layout->addWidget(mImg_img_button);
}

make_op::~make_op(void) {
	//delete mSelect_layout;

	//delete mImg_img_button;
	//delete mImg_img_widget;
	//delete mImg_img_layout;
}

inline void make_op::init_variable(void) {
	mSelect_layout = new QGridLayout;

	mImg_img_button = new BUTTON("img > img");
	mImg_img_widget = new QDialog;
	mImg_img_widget->setWindowTitle("img > img_model_list");
	mImg_img_layout = new QGridLayout;
	
}

QGridLayout* make_op::get_layout(const int32_t& flag_) {
	switch (flag_) {
	case ModelName::EM_ADD_TYPE::Add: {
		return mSelect_layout;
	}break;
	default: {
		return mSelect_layout;
	}break;
	}
}