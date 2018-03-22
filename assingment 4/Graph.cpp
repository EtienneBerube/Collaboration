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
/*
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

    for(Edge* e: edges){
        weight1 += e->getWeight();
    }

    for(Edge* e: rhs.getEdges()){
        weight2 += e->getWeight();
    }
    return weight1 < weight2;


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
    for(Edge* e: rhs.getEdges()){
        edges.push_back(new Edge(e->getStartNode(), e->getEndNode(), e->getWeight()));
    }

    for(Node* n: rhs.getNode()){
        nodes.push_back(new Node(n->getId(),n->getdegree()));
    }

    return *this;
}

*/
std::vector<Edge *> Graph::getEdges() const{
    return edges;
}

std::vector<Node *> Graph::getNode() const{
    return nodes;
}
/*
Graph& Graph::operator+(const Graph &rhs) {
    std::vector<Node*> tempNodes;
    std::vector<Edge*> tempEdges;

    for(Edge* e: rhs.getEdges()){
        tempEdges.push_back(new Edge(e->getStartNode(), e->getEndNode(), e->getWeight()));
    }
    for(Edge* e2: edges){
        for(Edge* e3: tempEdges)
            if(e2 != e3)
                tempEdges.push_back(new Edge(e2->getStartNode(), e2->getEndNode(), e2->getWeight()));
    }
    for(Node* n: rhs.getNode()){
        tempNodes.push_back(new Node(n->getId(),n->getdegree()));
    }
    for(Node *n2: nodes)
        for(Node *n3: tempNodes)
            if(n3 != n2)
                nodes.push_back(new Node(n2->getId(),n2->getdegree()));



    //return Graph(tempNodes,tempEdges);
}*/






