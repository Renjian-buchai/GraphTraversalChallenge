#include "convert_graph.hpp"

//converts between:
//-vector of vectors (two-dimensional vector) of ints
//-array of arrays (two-dimensional array) of ints

std::vector<std::vector<int>> convert_graph_ARR_TO_VEC(int **graph, int graphsize) {

	std::vector<std::vector<int>> toReturn = {};
	for(int i = 0; i < graphsize; i++) {

		std::vector<int> toAdd = {};
		for(int j = 0; j < graphsize; j++) {
			toAdd.push_back(graph[i][j]);
		}
		toReturn.push_back(toAdd);
	}
	return toReturn;
}

int **convert_graph_VEC_TO_ARR (std::vector<std::vector<int>> graph) {

	int **toReturn = new int*[graph.size()];
	for(int i = 0; i < graph.size(); i++) {
		toReturn[i] = new int[graph[i].size()];
	}

	for(int i = 0; i < graph.size(); i++) {for(int j = 0; j < graph[i].size(); j++) {
			toReturn[i][j] = graph[i][j];
	}}
	return toReturn;
}
