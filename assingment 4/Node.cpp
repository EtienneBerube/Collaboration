/*
 * COEN 244 Assignment 4
 * Etienne Berube: 40052212
 * Braldey Walsh: 40063018
 */
#include "Node.h"

//get the ID of the node
int Node::getId() const {
    return id;
}

//set the ID of the node
void Node::setId(int id) {
    Node::id = id;
}

//create node with passed IF
Node::Node(int id) {
    degree = 0;
    this->id = id;
}

//== operator -> Return 1 if they're equal, 0 if not
bool Node::operator==(const Node &rhs) const {
    return (id == rhs.id) && (degree == rhs.degree);
}

//!= operator, call == operator and rerturn opposite
bool Node::operator!=(const Node &rhs) const {
    return !(rhs == *this);
}

//create a node node identical to passed node
Node::Node(const Node &node) {
    id = node.getId();
    degree = node.getdegree();
}

//create node with given ID and degree
Node::Node(int id, int degree) {
    this->id = id;
    this-> degree = degree;
}

