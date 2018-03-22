//
// Created by Etienne on 17/03/2018.
//

#include "Graph.h"
#include "Edge.h"

Graph::Graph() {

}


Graph::~Graph() {
    for (unsigned int i = 0; i < nodes.size(); ++i) {
        delete nodes[i];
        nodes.erase(nodes.begin() + i);
    }

    for (unsigned int i = 0; i < edges.size(); ++i) {
        delete edges[i];
        edges.erase(edges.begin() + i);
    }
}

bool Graph::operator==(const Graph &rhs) const {
    if(edges.size != rhs.getEdges().size() )
    for(unsigned int i = 0; i < ){

    }
    for(Node* n: nodes){

    }
}

bool Graph::operator!=(const Graph &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Graph &graph) {
    os<<toString();
    return os;
}

bool Graph::operator<(const Graph &rhs) const {
    if (nodes < rhs.nodes)
        return true;
    if (rhs.nodes < nodes)
        return false;
    return edges < rhs.edges;
}

bool Graph::operator>(const Graph &rhs) const {
    return rhs < *this;
}


Graph &Graph::operator++() {
    for(Edge* e: edges)
        e->incrementWeight();
    return *this;
}

Graph &Graph::operator=(const Graph &rhs) {
    return <#initializer#>;
}


std::vector<Edge *> & Graph::getEdges() const{
    return edges;
}

std::vector<Node *> & Graph::getNode() const{
    return nodes;
}




