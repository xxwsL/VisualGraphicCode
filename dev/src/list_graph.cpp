#include "list_graph.hpp"

ListGraph::ListGraph(void) {
	
}

ListGraph::~ListGraph(void) {
	for (size_t i = 0; i < vecBUTTON.size(); ++i) {
		delete vecBUTTON[i];
	}
}

bool ListGraph::create_button(std::vector<ImageOpBase*>& vec_) {
	return true;
}