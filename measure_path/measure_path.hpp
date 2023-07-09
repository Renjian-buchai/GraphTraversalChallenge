#pragma once

#include <vector>
#include <string>

#define PATH_INVALID_NONEXISTENT_EDGE	-1 //tries to use an edge which doesn't exist
#define PATH_INVALID_INCOMPLETE		-2 //doesn't traverse all vertices



int measure_path_VEC(std::vector<int> path, std::vector<std::vector<int>> graph);

int measure_path_ARR(std::vector<int> path, int **graph, int graphsize);
