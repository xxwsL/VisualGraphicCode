#include "add_op.hpp"

AddOp::AddOp(void) : mButton("+")
{
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