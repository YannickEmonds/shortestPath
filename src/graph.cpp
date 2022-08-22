#include "graph.h"


// TODO
Graph::Graph()
{

}


// TODO
Graph::Graph(const EdgeList list)
{

}

Graph::Graph(const NodeArray nodes, const EdgeArray edges)
{
    this->nodes = nodes;
    this->edges = edges;
    numberOfNodes = nodes.size();
    numberOfEdges = edges.size();
}


std::pair<EdgeArray::const_iterator, EdgeArray::const_iterator> Graph::getEdgesForNode(NodeID id) const
{
    EdgeArray::const_iterator begin = edges.begin() + nodes[id];
    EdgeArray::const_iterator end = edges.begin() + nodes[id+1];
    return std::make_pair(begin, end);
}


std::size_t Graph::size() const
{
    return numberOfNodes;
}


std::size_t Graph::nEdges() const
{
    return numberOfEdges;
}


std::size_t Graph::getOutDegree(NodeID id) const
{
    return nodes[id+1] - nodes[id];
}
