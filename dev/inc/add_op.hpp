#pragma once
#ifndef _add_op_hpp_
#define _add_op_hpp_

#include "image_op_base.hpp"
#include "button.hpp"

#include <qwidget.h>
#include <qlayout.h>
#include <qwidget.h>

class AddOp : public QWidget, public ImageOpBase
{
	Q_OBJECT
	/*----------------------------data-------------------------------*/
public:
	QGridLayout mLayout;
	BUTTON mButton;
	/*----------------------------function-------------------------------*/
public:
	AddOp();
	~AddOp();


	virtual bool op(void);

	virtual bool display(void);

	virtual BUTTON* read_button(void);

private slots:
	void show_(void);
};
#endif