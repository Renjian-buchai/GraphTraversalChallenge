#include "measure_path.hpp"



int measure_path_VEC(std::vector<int> path, std::vector<std::vector<int>> graph) {
	int toReturn = 0;
	for(int i = 1; i < path.size(); i++) {
		toReturn += graph[i-1][i];
	}
	return toReturn;
}

int measure_path_ARR(std::vector<int> path, int **graph) {
	int toReturn = 0;
	for(int i = 1; i < path.size(); i++) {
		toReturn += graph[i-1][i];
	}
	return toReturn;
}
