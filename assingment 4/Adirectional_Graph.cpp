//
// Created by Etienne on 17/03/2018.
//

#include "Adirectional_Graph.h"
#include "Node.h"

bool A_Directional_Graph::addNode(Node &v) {
    nodes.push_back(&v);
    return true;
}

bool A_Directional_Graph::removeNode(Node &v) {
    int currentId = v.getId();

    for(unsigned int i =0; i < nodes.size(); ++i){
        if(currentId == nodes[i]->getId()){
            //TODO REMOVE EDGE IF CONNECTED || Dont forget to delete pointer
            nodes.erase(nodes.begin()+i);
            return true;
        }
    }
    return false;
}

bool A_Directional_Graph::addEdge(Edge &e) {
    edges.push_back(&e);
    return true;
}

bool A_Directional_Graph::remove(Edge &e) {
    int startId;
    int endId;
    //TODO finish || Dont forget to delete pointer
    return false;
}

bool A_Directional_Graph::removeMultipleEdges(Edge *e, int length) {
    return false;
}

bool A_Directional_Graph::searchNode(const Node &v) {
    for(Node* n: nodes){
        if (n->getId() == v.getId())
            return true;
    }
    return false;
}

bool A_Directional_Graph::searchEdge(const Edge &e) {
    return false;
}

void A_Directional_Graph::display(Edge &v) const {

}

void A_Directional_Graph::display(Node &e) const {

}

void A_Directional_Graph::display() const {

}

std::string A_Directional_Graph::toString() const {
    return nullptr;
}

bool A_Directional_Graph::clean() {
    return false;
}
