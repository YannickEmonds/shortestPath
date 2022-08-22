#include "graph.h"


Graph::Graph()
{

}


std::size_t Graph::size() const
{
    return numberOfNodes;
}


std::size_t Graph::nEdges() const
{
    return numberOfEdges;
}
