#pragma once

#include <vector>
#include <utility>
#include <iterator>
#include <cstddef>


using NodeID = std::size_t;
using NodeArray = std::vector<NodeID>;
using CEdge = std::pair<NodeID, float>;    // edge with cost
using EdgeArray = std::vector<CEdge>;


class EdgeList
{
private:
    std::vector<std::pair<NodeID, NodeID>> list;
public:
    // TODO
};


class Graph
{
private:
    NodeArray nodes;
    EdgeArray edges;
    std::size_t numberOfNodes;
    std::size_t numberOfEdges;
public:
    struct Iterator 
    {
        using iterator_category = std::input_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = NodeID;
        using pointer = NodeID*;
        using reference = NodeID&;

        Iterator(pointer ptr) : m_ptr(ptr) {}
    private:
        pointer m_ptr;
    };

    Graph();
    Graph(const EdgeList list);
    Graph(const NodeArray nodes, const EdgeArray edges);

    std::pair<EdgeArray::const_iterator, EdgeArray::const_iterator> getEdgesForNode(NodeID id) const;
    
    std::size_t size() const;
    std::size_t nEdges() const;
    std::size_t getOutDegree(NodeID) const;
};
