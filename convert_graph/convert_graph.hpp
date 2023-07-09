#pragma once

#include <vector>

//converts between:
//-vector of vectors (two-dimensional vector) of ints
//-array of arrays (two-dimensional array) of ints

std::vector<std::vector<int>>	convert_graph_ARR_TO_VEC	(int **graph, int graphsize);
int **				convert_graph_VEC_TO_ARR	(std::vector<std::vector<int>> graph);
