#pragma once
#ifndef _button_hpp_
#define _button_hpp_

#include <QToolButton>

class BUTTON : public QToolButton {
	Q_OBJECT
	/*----------------------------function-------------------------------*/
public:
	explicit BUTTON(const QString &text, QWidget *parent = 0);

	QSize sizeHint(void) const override;
};

#endif