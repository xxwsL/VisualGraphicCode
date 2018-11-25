#pragma once
#ifndef _add_op_hpp_
#define _add_op_hpp_

#include "image_op_base.hpp"
#include "button.hpp"
#include "model_name.hpp"

#include <qwidget.h>
#include <qlayout.h>

#include <qwidget.h>

#include <vector>

class AddOp : public QWidget, public ImageOpBase
{
	Q_OBJECT
	/*----------------------------data-------------------------------*/
public:
	QGridLayout *mLayout = nullptr;
	BUTTON mButton;

	typedef struct {
		size_t siLoca_seq = 0;
		std::pair<int32_t*, std::string*>  TYPE;
		std::vector<ImageOpBase*> *ptrBase_list;
	}USTR;

	USTR mUstr;
	/*----------------------------function-------------------------------*/
public:
	AddOp(std::vector<ImageOpBase*> *ptr_base_list_);
	~AddOp(void);


	inline virtual bool op(void);

	virtual void display(void);

	virtual BUTTON* read_button(void);

private:
	inline void set(int32_t *ptr_int32_, std::string *ptr_str_);

private slots:
	void QT_show(void);
};
#endif