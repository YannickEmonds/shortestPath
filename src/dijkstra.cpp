#include <utility>
#include <vector>
#include <limits>
#include "graph.h"
#include "priority_queue.h"

using NodeID = std::size_t;

// Implementation of Dijkstra's algorithm (naive version).
// Inputs: Graph containing nodes and weights edges
//         starting node (node ID)
// Outputs: distances to starting node (vector)
//          parent nodes (vector)
std::pair<std::vector<float>, std::vector<NodeID>> dijkstra_sp(const Graph graph,
                                                                const NodeID startID)
{
    std::vector<float> distances(graph.size(), std::numeric_limits<float>::infinity());
    std::vector<NodeID> parent(graph.size(), std::numeric_limits<float>::quiet_NaN());
    PriorityQueue<NodeID, float> pq;

    distances[startID] = 0.0f;
    parent[startID] = startID;

    pq.insert(startID, distances[startID]);
    while (not pq.isEmpty())
    {
        NodeID u = pq.deleteMin();
        // iterate over edges from u 
        // --> in class Graph, implement iterator over edges
    }

    return std::make_pair(distances, parent);
}
