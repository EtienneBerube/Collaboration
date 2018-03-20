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

