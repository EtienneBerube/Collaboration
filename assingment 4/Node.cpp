//
// Created by Etienne on 17/03/2018.
//

#include "Node.h"

int Node::getId() const {
    return id;
}

void Node::setId(int id) {
    Node::id = id;
}

Node::Node(int id) {
    degree = 0;
    this->id = id;
}

bool Node::operator==(const Node &rhs) const {
    return id == rhs.id &&
           degree == rhs.degree;
}

bool Node::operator!=(const Node &rhs) const {
    return !(rhs == *this);
}

Node::Node(const Node &node) {
    id = node.getId();
    degree = node.getdegree();
}

Node::Node(int id, int degree) {
    this->id = id;
    this-> degree = degree;
}

