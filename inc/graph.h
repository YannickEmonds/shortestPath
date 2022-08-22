#include <vector>


using NodeID = std::size_t;


class Graph
{
private:
    std::vector<NodeID> nodes;
    std::vector<NodeID> edges;
    std::size_t numberOfNodes;
    std::size_t numberOfEdges;
public:
    Graph();

    std::size_t size() const;
    std::size_t nEdges() const;
};
