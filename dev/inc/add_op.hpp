#pragma once
#ifndef _add_op_hpp_
#define _add_op_hpp_

#include "image_op_base.hpp"
#include "button.hpp"
#include "model_name.hpp"
#include "make_op.hpp"

#include <qwidget.h>
#include <qlayout.h>

#include <qwidget.h>
#include <qdialog.h>

#include <vector>
/*
Ä£¿éÌí¼ÓÄ£¿é
*/
class AddOp : public QDialog, public ImageOpBase
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
	AddOp(void);
	~AddOp(void);
	AddOp(std::vector<ImageOpBase*> *ptr_base_list_, int32_t *ptr_int32_, std::string *ptr_str_);

	inline virtual bool op(void);

	virtual void display(void);

	virtual BUTTON* read_button(void);

	static ImageOpBase* create(int32_t *flag_);

private:
	inline void set(std::vector<ImageOpBase*> *ptr_base_list_, int32_t *ptr_int32_, std::string *ptr_str_);

private slots:
	void QT_show(void);
};
#endif