//
// Created by Etienne on 17/03/2018.
//

#include "Edge.h"

Edge::Edge(Node *n1, Node *n2)
{
	setStartNode(n1->getId());
	setEndNode(n2->getId());
}

bool Edge::operator==(const Edge &rhs) const {
    return startNode == rhs.startNode &&
           endNode == rhs.endNode &&
           weight == rhs.weight;
}

bool Edge::operator!=(const Edge &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Edge &edge) {
    os << edge.startNode << "->" << edge.endNode;
    return os;
}

Edge::Edge(const Edge &edge) {
    startNode = edge.getStartNode();
    endNode = edge.getEndNode();
    weight = edge.getWeight();
}

Edge::Edge(int id1, int id2, int weight) {
    startNode = id1;
    endNode = id2;
    this->weight = weight;
}




