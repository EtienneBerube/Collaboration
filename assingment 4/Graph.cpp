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
    if(edges.size() != rhs.getEdges().size() || nodes.size() != rhs.getNode().size())
        return false;

    std::vector<Edge*> tempEdge = rhs.getEdges();
    for(unsigned int i = 0; i < edges.size(); i++){
        if(edges[i] != tempEdge[i])
            return false;
    }
    std::vector<Node*> tempNode = rhs.getNode();
    for(unsigned int i = 0; i < nodes.size(); i++){
        if(nodes[i] != tempNode[i])
            return false;
    }
    return true;
}

bool Graph::operator!=(const Graph &rhs) const {
    return !(rhs == *this);
}

bool Graph::operator<(const Graph &rhs) const {
    int weight1 =0;
    int weight2 =0;


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
    return ;
}


std::vector<Edge *> Graph::getEdges() const{
    return edges;
}

std::vector<Node *> Graph::getNode() const{
    return nodes;
}




