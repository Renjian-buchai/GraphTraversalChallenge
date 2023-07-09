#include "measure_path.hpp"



int measure_path_VEC(std::vector<int> path, std::vector<std::vector<int>> graph) {
	int toReturn = 0;

	std::vector<bool> wasVisited(graph.size(), false);
	wasVisited[path[0]] = true;
	for(int i = 1; i < path.size(); i++) {
		if(graph[i-1][i] == -1) {return PATH_INVALID_NONEXISTENT_EDGE;}
		wasVisited[path[i]] = true;
		toReturn += graph[i-1][i];
	}
	for(int i = 0; i < wasVisited.size(); i++) {
		if(wasVisited[i] == false) {return PATH_INVALID_INCOMPLETE;}
	}
	return toReturn;
}

int measure_path_ARR(std::vector<int> path, int **graph, int graphsize) {
	int toReturn = 0;

	std::vector<bool> wasVisited(graphsize, false);
	wasVisited[path[0]] = true;
	for(int i = 1; i < path.size(); i++) {
		if(graph[i-1][i] == -1) {return PATH_INVALID_NONEXISTENT_EDGE;}
		wasVisited[path[i]] = true;
		toReturn += graph[i-1][i];
	}
	for(int i = 0; i < wasVisited.size(); i++) {
		if(wasVisited[i] == false) {return PATH_INVALID_INCOMPLETE;}
	}
	return toReturn;
}
