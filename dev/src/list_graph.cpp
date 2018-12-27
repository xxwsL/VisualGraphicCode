#include "list_graph.hpp"

ListGraph::ListGraph(void) {
	//BUTTON *mInit = new BUTTON(tr("+"));
	//vecBUTTON.push_back(mInit);
	//mLayout.addWidget(vecBUTTON[0], 0, 0);
	//setLayout(&mLayout);
}

ListGraph::~ListGraph(void) {
}

ListGraph::ListGraph(const std::string& name_) {
	this->setWindowTitle(tr(name_.c_str()));
}

bool ListGraph::add_button(BUTTON *button_, int seq_) {
	if (seq_ < 0 || seq_ >= vecBUTTON.size()) {
		vecBUTTON.push_back(button_);
		mLayout.addWidget(button_, 0, (int)vecBUTTON.size(), 1, 1);
		this->setLayout(&mLayout);
		this->show();
	}
	else {
		vecBUTTON.insert(vecBUTTON.begin() + seq_, button_);
		for (size_t i = 0; i < vecBUTTON.size(); ++i) {
			mLayout.addWidget(vecBUTTON[i]);
		}
		this->setLayout(&mLayout);
		this->show();
	}
	return true;
}