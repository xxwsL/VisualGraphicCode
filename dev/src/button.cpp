#include "button.hpp"

BUTTON::BUTTON(void){}

BUTTON::BUTTON(const QString &text, QWidget *parent)
	: QToolButton(parent)
{
	this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	this->setText(text);
}


QSize BUTTON::sizeHint(void) const {
	QSize size = QToolButton::sizeHint();
	size.rheight() += 20;
	size.rwidth() = qMax(size.width(), size.height());
	return size;
}

void BUTTON::init_set(const QString &text) {
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	setText(text);
}
