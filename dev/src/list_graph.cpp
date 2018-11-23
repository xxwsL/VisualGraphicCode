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
	setWindowTitle(tr(name_.c_str()));
}

bool ListGraph::add_button(BUTTON *button_, int seq_) {
	if (seq_ == -1) {
		mLayout.addWidget(button_, 0, (int)vecBUTTON.size());
		vecBUTTON.push_back(button_);
		this->setLayout(&mLayout);
		this->show();
	}
	else {
		vecBUTTON.insert(vecBUTTON.begin() + seq_, button_);
	}
	return true;
}