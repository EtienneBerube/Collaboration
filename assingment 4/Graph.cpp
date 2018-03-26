//
// Created by Etienne on 17/03/2018.
//

#include "Graph.h"
#include "Edge.h"

Graph::Graph() {

}

Graph::Graph(std::vector<Node *> &n, std::vector<Edge *> &e) {
    nodes = n;
    edges = e;
}


Graph::~Graph() {}

std::vector<Edge *> Graph::getEdges() const{
    return edges;
}

std::vector<Node *> Graph::getNode() const{
    return nodes;
}







