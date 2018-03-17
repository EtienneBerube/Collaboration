//
// Created by Etienne on 17/03/2018.
//

#include "Adirectional_Graph.h"
#include "Node.h"
#include "Edge.h"

bool ADirectional_Graph::addNode(Node &v) {
    nodes.push_back(&v);
    return true;
}

bool ADirectional_Graph::removeNode(Node &v) {
    int currentId = v.getId();

    if(!searchNode(v))
        return false;

    for(unsigned int i =0; i < nodes.size(); ++i){
        if(currentId == nodes[i]->getId()){
            for(Edge* e: edges){
                if(e->getEndNode() == currentId || e->getStartNode() == currentId){
                    removeEdge(*e);
                }
            }
            delete nodes[i];
            nodes.erase(nodes.begin()+i);
            return true;
        }
    }
    return false;
}

bool ADirectional_Graph::addEdge(Edge &e) {
    edges.push_back(&e);
    return true;
}

bool ADirectional_Graph::removeEdge(Edge &e) {
<<<<<<< HEAD
    int startId = e.getStartNode();
	int endId = e.getEndNode();

	for (unsigned int i = 0; i < edges.size(); i++)
	{
		if
	}
    //TODO finish || Dont forget to delete pointer
=======
    int startId;
    int endId;

>>>>>>> 4282808ee7f5ccccec2d2ff22d3575ed20d18ae6
    return false;
}

bool ADirectional_Graph::removeMultipleEdges(Edge *e, int length) {
    return false;
}

bool ADirectional_Graph::searchNode(const Node &v) {
    for(Node* n: nodes){
        if (n->getId() == v.getId())
            return true;
    }
    return false;
}

bool ADirectional_Graph::searchEdge(const Edge &e) {
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
	//blah, blah blah
    return false;
}

void ADirectional_Graph::display(Edge &v) const {

}

void ADirectional_Graph::display(Node &e) const {

}
//Adjencency Matrix
void ADirectional_Graph::display() const {

}

std::string ADirectional_Graph::toString() const {
    return nullptr;
}

bool ADirectional_Graph::clean() {
    try {
        for (unsigned int i = 0; i < nodes.size(); ++i) {
            delete nodes[i];
            nodes.erase(nodes.begin() + i);
        }

        for (unsigned int i = 0; i < edges.size(); ++i) {
            delete edges[i];
            edges.erase(edges.begin() + i);
        }
    }catch (...){
        std::cout<<"An error has occured when clearing the graph"<<std::endl;
        return false;
    }
    return true;
}

int ADirectional_Graph::getIndexNode(Node &n) {
    return 0;
}

int ADirectional_Graph::getIndexEgde(Edge &e) {
    return 0;
}
