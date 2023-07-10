#include "measure_path.hpp"

#include <vector>

int measure_path_VEC(std::vector<int> path,
                     std::vector<std::vector<int>> graph) {
  int toReturn = 0;

  std::vector<bool> wasVisited(graph.size(), false);
  wasVisited[path[0]] = true;
  for (int i = 1; i < path.size(); i++) {
    if (graph[i - 1][i] == -1) {
      return PATH_INVALID_NONEXISTENT_EDGE;
    }
    wasVisited[path[i]] = true;
    toReturn += graph[i - 1][i];
  }
  for (int i = 0; i < wasVisited.size(); i++) {
    if (wasVisited[i] == false) {
      return PATH_INVALID_INCOMPLETE;
    }
  }
  return toReturn;
}

int measure_path_ARR(std::vector<int> path, int **graph, int graphsize) {
  int toReturn = 0;

  std::vector<bool> wasVisited(graphsize, false);
  wasVisited[path[0]] = true;
  for (int i = 1; i < path.size(); i++) {
    if (graph[i - 1][i] == -1) {
      return PATH_INVALID_NONEXISTENT_EDGE;
    }
    wasVisited[path[i]] = true;
    toReturn += graph[i - 1][i];
  }
  for (int i = 0; i < wasVisited.size(); i++) {
    if (wasVisited[i] == false) {
      return PATH_INVALID_INCOMPLETE;
    }
  }
  return toReturn;
}

template <typename containerIterator>
int measure_path(std::vector<int> path, containerIterator begin,
                 containerIterator end) {
  int toReturn = 0;
  std::vector<std::vector<int>> graph(begin, end);

  std::vector<bool> wasVisited(graph.size(), false);
  wasVisited[path[0]] = true;
  for (int i = 1; i < path.size(); i++) {
    if (graph[i - 1][i] == -1) {
      return PATH_INVALID_NONEXISTENT_EDGE;
    }
    wasVisited[path[i]] = true;
    toReturn += graph[i - 1][i];
  }
  for (int i = 0; i < wasVisited.size(); i++) {
    if (wasVisited[i] == false) {
      return PATH_INVALID_INCOMPLETE;
    }
  }
  return toReturn;
}

/**
 * Usage:
 *
 * std::vector<>:
 * measure_path(path, graph.begin(), graph.end());
 *
 * int[][]:
 * measure_path(path, std::begin(graph), std::end(graph))
 *
 */
