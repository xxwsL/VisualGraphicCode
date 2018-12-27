#include "make_op.hpp"
 
ImageOpBase *make_op::ptrMake_op = nullptr;
int32_t make_op::ptrCreate_flag = NULL;

make_op::MAKE_GUI make_op::mMake_GUI;

make_op::make_op(void) {
	//��ʼ��GUI
	init_GUI();

	//����img_imgģ������dialog
	connect(mMake_GUI.mImg_img_button, &QToolButton::clicked, [](){
		mMake_GUI.mImg_img_dialog->exec();
	});
	//img_imgģ������dialog���ò���
	mMake_GUI.mImg_img_dialog->setLayout(mMake_GUI.mImg_img_layout);

	//allģ�����ɲ������img_img��ť����
	mMake_GUI.mSelect_layout->addWidget(mMake_GUI.mImg_img_button);
}

make_op::~make_op(void) {
	//delete mSelect_layout;

	//delete mImg_img_button;
	//delete mImg_img_widget;
	//delete mImg_img_layout;
}

/*
>> ��ȡ����ָ��
flag_ : ��ȡ���ֵ�����
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
>> ��ʼ��GUI
*/
void make_op::init_GUI(void) {
	mMake_GUI.mSelect_layout = new QGridLayout;

	//img_imgģ��GUI����
	mMake_GUI.mImg_img_button = new BUTTON("img > img");
	mMake_GUI.mImg_img_dialog = new QDialog;
	mMake_GUI.mImg_img_dialog->setWindowTitle("img > img_model_list");
	mMake_GUI.mImg_img_layout = new QGridLayout;

	//��ʼ��button
	init_button();
}

/*
>> ��ʼ��button
*/
void make_op::init_button(void) {
	//��ʼ�� Gray ģ��
	BUTTON *mGray = new BUTTON("Gray");
	connect(mGray, &QToolButton::clicked, []() {
		ptrMake_op = Gray_op::create(nullptr);
		ptrCreate_flag = ModelName::iGray;
	});
	mMake_GUI.mImg_img_layout->addWidget(mGray);
}