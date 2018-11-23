#include "add_op.hpp"

AddOp::AddOp(void) : mButton("+")
{
	setLayout(&mLayout);
	connect(&mButton, SIGNAL(clicked()), this, SLOT(show_()));
}

AddOp::~AddOp(void){}


bool AddOp::op(void) {
	return true;
}

bool AddOp::display(void) {
	return true;
}

BUTTON* AddOp::read_button(void) {
	return &mButton;
}


void AddOp::show_(void) {
	this->show();
}