//
// Created by Etienne on 17/03/2018.
//

#include "Adirectional_Graph.h"
#include "Node.h"
#include "Edge.h"

bool ADirectional_Graph::addNode(Node &v) {
    if(!searchNode(v)) {
        nodes.push_back(&v);
        return true;
    }
    std::cout<<"Node already exists, Change ID to add node to graph";
    return false;

}

bool ADirectional_Graph::removeNode(Node &v) {
	int currentId = v.getId();

	if (!searchNode(v))
		return false;

	for (unsigned int i = 0; i < nodes.size(); ++i) {
		if (currentId == nodes[i]->getId()) {
			for (Edge* e : edges) {
				if (e->getEndNode() == currentId || e->getStartNode() == currentId) {
					removeEdge(*e);
				}
			}
			delete nodes[i];
			nodes.erase(nodes.begin() + i);
			return true;
		}
	}
	return false;
}

bool ADirectional_Graph::addEdge(Edge &e) {

    if(!searchEdge(e)) {
        edges.push_back(&e);
        nodes[getIndexNode(e.getStartNode())]->incrementDegree();
        //nodes[getIndexNode(e.getEndNode())]->incrementDegree();
        return true;
    }
    std::cout<<"Edge already exists, duplicates are not allowed in bi-direcitonal graphs";
    return false;
}

bool ADirectional_Graph::removeEdge(Edge &e) {

	int startId = e.getStartNode();
	int endId = e.getEndNode();

	if (searchEdge(e)) {
		for (unsigned int i = 0; i < edges.size(); i++) {
			if (edges.at(i)->getStartNode() == startId && edges.at(i)->getEndNode() == endId)
			{
                nodes[getIndexNode(e.getStartNode())]->decrementDegree();
                //nodes[getIndexNode(e.getEndNode())]->decrementDegree();
                delete edges.at(i);
				edges.erase(edges.begin() + i);
				
			}
		}
	}
	return false;
}

bool ADirectional_Graph::removeMultipleEdges(Edge *e, int length) {
	
	for (unsigned int i = 0; i < length; i++)
		removeEdge(e[i]);
		delete[] e;

	
	return true;
}

bool ADirectional_Graph::searchNode(const Node &v) {
	for (Node* n : nodes) {
		if (n->getId() == v.getId())
			return true;
	}
	return false;
}

bool ADirectional_Graph::searchEdge(const Edge &e) {
	//go through all edges in vector and compare the weight.
	//If they have the same weight, check their start and end ID
	//if all three values are the same, they're identical
	for (Edge* ed : edges)
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
//Assume path starts at 1

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
	}
	catch (...) {
		std::cout << "An error has occured when clearing the graph" << std::endl;
		return false;
	}
	return true;
}


int ADirectional_Graph::getIndexNode(Node &v) {
    for(unsigned int i =0 ; i< nodes.size(); i++){
        if(nodes[i]->getId() == v.getId())
            return i;
    }
    return -1;
}

int ADirectional_Graph::getIndexNode(int id) {
    for(unsigned int i =0 ; i< nodes.size(); i++){
        if(nodes[i]->getId() == id)
            return i;
    }
    return -1;
}

int ADirectional_Graph::getIndexEgde(Edge &e) {
    for(unsigned int i =0 ; i< nodes.size(); i++){
        if(edges[i]->getStartNode() == e.getStartNode() && edges[i]->getEndNode() == e.getEndNode())
            return i;
    }
    return -1;;
}

int ADirectional_Graph::getIndexEgde(int id) {
    for (unsigned int i = 0; i < nodes.size(); i++) {
        if (edges[i]->getStartNode() == id && edges[i]->getEndNode() == id)
            return i;
    }
    return -1;;
}

void ADirectional_Graph::PathFinderStart(){
    PathFinder(*nodes[0], *nodes[0], *nodes[0],*nodes[getIndexNode(edges[0]->getEndNode())],,false;
}

void ADirectional_Graph::pathFinder(Node &start, Node &previous, Node& current ,Node &next,std::string path, bool flag){
    //USE STACK !!!
    Node currentNode = next;
    for(unsigned int i = 0; i < edges.size();++i){
        if(currentNode.getId() == start.getId()) {
            std::cout << path << std::endl;
            break;
            flag = true;
        }else if(flag != false){

        }else{
            return;
        }

    }
}