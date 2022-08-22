#pragma once

#include <vector>
#include <utility>
#include "graph.h"

std::pair<std::vector<float>, std::vector<NodeID>> dijkstra_sp(const Graph graph,
                                                               const NodeID startID);
                                                               