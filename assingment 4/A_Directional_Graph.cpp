//
// Created by Etienne on 17/03/2018.
//

#include "A_Directional_Graph.h"
#include "Node.h"
#include "Edge.h"

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
	//go through all edges in vector and compare the weight.
	//If they have the same weight, check their start and end ID
	//if all three values are the same, they're identical
	for (Edge* ed: edges)
	{
		if (ed->getWeight() == e.getWeight())
		{
			//check the start and end points
			if (ed->getStartNode() == e.getStartNode() && ed->getEndNode() == e.getEndNode())
				return true;
		}
	}
	
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