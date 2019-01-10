#include "operator_op.hpp"
#include "model_name.hpp"
#include "xxwsL_debug.hpp"

Operator_big::Operator_big(void) {
	mUstr.TYPE = &ModelName::i32Mat_mat;
	mUstr.strName = &ModelName::strOperator_big;
	mUstr.mButton.init_set(ModelName::strOperator_big.c_str());
	mUstr.mInterface.first = nullptr;
	mUstr.mInterface.second = nullptr;

	mUstr.dValue = 127;

	//设置滑动条的方向
	mUstr.mSlider.setOrientation(Qt::Horizontal);
	//设置滑动条控件的最小值
	mUstr.mSlider.setMinimum(0);
	//设置滑动条控件的最大值
	mUstr.mSlider.setMaximum(255);
	//设置滑动条控件的值
	mUstr.mSlider.setValue(mUstr.dValue);
	//设置滑动条控件的步长
	mUstr.mSlider.setSingleStep(1);
	
	//设置微调框的最小值
	mUstr.mSpinBox.setMinimum(0);
	//设置微调框的最大值
	mUstr.mSpinBox.setMaximum(255);
	//设置微调框的初始值
	mUstr.mSpinBox.setValue(mUstr.dValue);
	//设置微调框的步长
	mUstr.mSpinBox.setSingleStep(1);

	//设置布局
	mUstr.mLayout.addWidget(&mUstr.mSlider);
	mUstr.mLayout.addWidget(&mUstr.mSpinBox);
	this->setLayout(&mUstr.mLayout);
	
	connect(&mUstr.mSlider, &QSlider::valueChanged, this, &Operator_big::set_LineEdit_Value);
	connect(&mUstr.mSpinBox, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &Operator_big::set_slider_Value);

	connect(&mUstr.mButton, &QToolButton::clicked, this, &Operator_big::exec);
}

Operator_big::~Operator_big(void) {
	if (mUstr.mInterface.second) {
		delete mUstr.mInterface.second;
	}
}

bool Operator_big::op(void) {
	*mUstr.mInterface.second = *mUstr.mInterface.first > mUstr.dValue;
	return true;
}

void Operator_big::display(void) const{
	cv::imshow("Operator_big_image", *mUstr.mInterface.second);
}

BUTTON* Operator_big::read_button_ptr(void) {
	return &mUstr.mButton;
}

void* Operator_big::read_interface_ptr(void) {
	return mUstr.mInterface.second;
}

void Operator_big::load_interface_ptr(void* ptrInterface_, void* ptrList_) {
	cv::Mat* ptrMat = (cv::Mat*)ptrInterface_;
	if (ptrMat->empty()) {
#ifdef XXWSL_DEBUG
		QMessageBox msgBox;
		msgBox.setText("Error : Operator_big->load_interface_ptr : parame interface_ is empty");
		msgBox.exec();
#endif
		exit(1);
	}
	else {
		mUstr.mInterface.first = ptrMat;
		mUstr.mInterface.second = new cv::Mat;
		ptrMat->copyTo(*mUstr.mInterface.second);
		mUstr.ptrBase_list = (OpList*)ptrList_;
	}
}

int32_t Operator_big::read_i32_type(void) const {
	return *mUstr.TYPE;
}

void Operator_big::set_LineEdit_Value(const int& value_) {
	mUstr.dValue = (double)value_;
	mUstr.mSpinBox.setValue(value_);
	mUstr.ptrBase_list->run();
}

void Operator_big::set_slider_Value(const int& value_) {
	mUstr.dValue = (double)value_;
	mUstr.mSlider.setValue(value_);
	mUstr.ptrBase_list->run();
}

