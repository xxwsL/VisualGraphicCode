#include "button.hpp"


BUTTON::BUTTON(const QString &text, QWidget *parent)
	: QToolButton(parent)
{
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	setText(text);
}


QSize BUTTON::sizeHint(void) const {
	QSize size = QToolButton::sizeHint();
	size.rheight() += 20;
	size.rwidth() = qMax(size.width(), size.height());
	return size;
}
