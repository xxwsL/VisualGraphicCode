#include "make_op.hpp"
 
ImageOpBase *make_op::ptrMake_op = nullptr;

QGridLayout *make_op::mSelect_layout = nullptr;

BUTTON *make_op::mImg_img_button = nullptr;
QWidget *make_op::mImg_img_widget = nullptr;
QGridLayout *make_op::mImg_img_layout = nullptr;

inline void make_op::init(void) {
	make_op();

	connect(mImg_img_button, &QToolButton::clicked, [](){
		mImg_img_widget->show();
	});

	mSelect_layout->addWidget(mImg_img_button);
}

inline void make_op::remove_init(void) {
	delete mSelect_layout;

	delete mImg_img_button;
	delete mImg_img_widget;
	delete mImg_img_layout;
}

inline void make_op::init_variable(void) {
	mSelect_layout = new QGridLayout;

	mImg_img_button = new BUTTON("img > img");
	mImg_img_widget = new QWidget;
	mImg_img_widget->setWindowTitle("img > img_model_list");
	mImg_img_layout = new QGridLayout;
	
}