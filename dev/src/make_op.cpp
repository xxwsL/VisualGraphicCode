#include "make_op.hpp"
#include "xxwsL_debug.hpp"
 
ImageOpBase *make_op::ptrMake_op = nullptr;
int32_t make_op::ptrCreate_flag = NULL;

make_op::MAKE_GUI make_op::mMake_GUI;
make_op::MODEL_BUTTON make_op::mMake_button;

make_op::make_op(void) {
	//初始化GUI
	init_GUI();

	//装载mat_mat布局
	mMake_GUI.mMat_mat_dialog_0->setLayout(mMake_GUI.ptrMat_mat_layout_0);
	mMake_GUI.mMat_mat_dialog_1->setLayout(mMake_GUI.ptrMat_mat_layout_1);

	//mat_all布局添加部件
	mMake_GUI.ptrMat_all_layout->addWidget(mMake_GUI.ptrMat_mat_button);
	//装载mat_all布局
	mMake_GUI.ptrMat_all_dialog->setLayout(mMake_GUI.ptrMat_all_layout);

}

make_op::~make_op(void) {
}

void make_op::close(void) {
	if (mMake_GUI.ptrMat_all_layout) { delete mMake_GUI.ptrMat_all_layout; mMake_GUI.ptrMat_all_layout = nullptr; }
	if (mMake_GUI.ptrMat_all_dialog) { delete mMake_GUI.ptrMat_all_dialog; mMake_GUI.ptrMat_all_dialog = nullptr; }

	if (mMake_GUI.ptrMat_mat_button) { delete mMake_GUI.ptrMat_mat_button; mMake_GUI.ptrMat_mat_button = nullptr; }
	if (mMake_GUI.ptrMat_mat_layout_0) { delete mMake_GUI.ptrMat_mat_layout_0; mMake_GUI.ptrMat_mat_layout_0 = nullptr; }
	if (mMake_GUI.ptrMat_mat_layout_1) { delete mMake_GUI.ptrMat_mat_layout_1; mMake_GUI.ptrMat_mat_layout_1 = nullptr; }
	if (mMake_GUI.mMat_mat_dialog_0) { delete mMake_GUI.mMat_mat_dialog_0; mMake_GUI.mMat_mat_dialog_0 = nullptr; }
	if (mMake_GUI.mMat_mat_dialog_1) { delete mMake_GUI.mMat_mat_dialog_1; mMake_GUI.mMat_mat_dialog_1 = nullptr; }

	if (mMake_button.mGray_0) { delete mMake_button.mGray_0; mMake_button.mGray_0 = nullptr; }
	if (mMake_button.mGray_1) { delete mMake_button.mGray_1; mMake_button.mGray_1 = nullptr; }
		
}

/*
读取布局指针
flag_ : 读取布局的类型
*/
QLayout* make_op::read_layout_ptr(const int32_t& flag_) {
	switch (flag_) {
	case ModelName::EM_MAT_TYPE::Mat_all: {
		return mMake_GUI.ptrMat_all_layout;
	}break;
	case ModelName::EM_MAT_TYPE::Mat_mat: {
		return  mMake_GUI.ptrMat_mat_layout_0;
	}break;
	default: {
#ifdef XXWSL_DEBUG
		QMessageBox msgBox;
		msgBox.setText(tr("Error : make_op->read_layout_ptr flag_ is no code"));
		msgBox.exec();
		exit(1);
#endif
	}break;
	}
}

QDialog* make_op::read_dialog_ptr(const int32_t& flag_) {
	switch (flag_) {
	case ModelName::EM_MAT_TYPE::Mat_all: {
		return mMake_GUI.ptrMat_all_dialog;
	}break;
	case ModelName::EM_MAT_TYPE::Mat_mat: {
		return  mMake_GUI.mMat_mat_dialog_0;
	}break;
	default: {
#ifdef XXWSL_DEBUG
		QMessageBox msgBox;
		msgBox.setText(tr("Error : make_op->read_layout_ptr flag_ is no code"));
		msgBox.exec();
		exit(1);
#endif
	}break;
	}
}

/*
>> 初始化GUI
*/
void make_op::init_GUI(void) {
	//mat_all模块GUI部分
	mMake_GUI.ptrMat_all_layout = new QGridLayout;
	mMake_GUI.ptrMat_all_dialog = new QDialog;
	mMake_GUI.ptrMat_all_dialog->setWindowTitle("mat->all_list");
	
	//mat_mat模块GUI部分
	mMake_GUI.ptrMat_mat_button = new BUTTON("mat->mat");
	mMake_GUI.ptrMat_mat_layout_0 = new QGridLayout;
	mMake_GUI.ptrMat_mat_layout_1 = new QGridLayout;
	mMake_GUI.mMat_mat_dialog_0 = new QDialog;
	mMake_GUI.mMat_mat_dialog_1 = new QDialog;
	mMake_GUI.mMat_mat_dialog_0->setWindowTitle("mat->mat_list");
	mMake_GUI.mMat_mat_dialog_1->setWindowTitle("mat->mat_list");
		
	//初始化 Gray 模块
	mMake_button.mGray_0 = new BUTTON("Gray");
	mMake_button.mGray_1 = new BUTTON("Gray");

	//初始化button
	init_button();
}

/*
初始化button
*/
void make_op::init_button(void) {
	
	//连接Gray创建模块mat->mat
	connect(mMake_button.mGray_0, &QToolButton::clicked, []() {
		ptrMake_op = new Gray_op;
		ptrCreate_flag = ModelName::i32Mat_mat;
	});
	mMake_GUI.ptrMat_mat_layout_0->addWidget(mMake_button.mGray_0);
	
	//连接Gray创建模块mat->all
	connect(mMake_button.mGray_1, &QToolButton::clicked, []() {
		ptrMake_op = new Gray_op;
		ptrCreate_flag = ModelName::i32Mat_mat;
	});
	mMake_GUI.ptrMat_mat_layout_1->addWidget(mMake_button.mGray_1);

	//连接mat_mat模块生成dialog
	connect(mMake_GUI.ptrMat_mat_button, &QToolButton::clicked, []() {
		mMake_GUI.mMat_mat_dialog_1->exec();
	});

	
}


int32_t* make_op::switch_type(const int32_t& i32Left, const int32_t& i32Right) {
	int32_t i32Code = i32Left / MAT_ALL_TYPE * 100 + i32Right / 100;
	switch (i32Code) {
	case ModelName::EM_MAT_TYPE::Mat_all : return &ModelName::i32Mat_all;
	case ModelName::EM_MAT_TYPE::Mat_mat : return &ModelName::i32Mat_mat;
	default: {
#ifdef XXWSL_DEBUG
		QMessageBox msgBox;
		msgBox.setText(tr("Error : make_op->switch_type code is error"));
		msgBox.exec();
		exit(1);
#else
		return nullptr;
#endif
	}break;
	}
}