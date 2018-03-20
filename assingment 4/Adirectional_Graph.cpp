//
// Created by Etienne on 17/03/2018.
//

#include <algorithm>
#include "Adirectional_Graph.h"
#include "Node.h"
#include "Edge.h"

//*****************************COMPARATOR*****************************
struct CompareEdges
{
    bool operator()( const Edge* e1, const Edge* e2 ) const {
        if(e1->getStartNode() < e2->getStartNode())
            return true;
        if(e1->getStartNode() == e2->getStartNode())
            return e1->getEndNode() < e2->getEndNode();
        else
            return false;
    }
};

struct CompareNodes
{
    bool operator()( const Node* e1, const Node* e2 ) const {
        if(e1->getId() < e2->getId())
            return true;
        else
            return false;
    }
};

//*****************************COMPARATOR*****************************

bool ADirectional_Graph::addNode(Node &v) {
    if (!searchNode(v)) {
        nodes.push_back(&v);
        sortNodeVector();
        return true;
    }
    std::cout << "Node already exists, Change ID to add node to graph";
    return false;

}

bool ADirectional_Graph::removeNode(Node &v) {
    int currentId = v.getId();

    if (!searchNode(v))
        return false;

    for (unsigned int i = 0; i < nodes.size(); ++i) {
        if (currentId == nodes[i]->getId()) {
            for (Edge *e : edges) {
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

    if (!searchEdge(e)) {
        if(!searchNode(e.getStartNode()) || !searchNode(e.getEndNode())){
            std::cout<<"One or more nodes to be connected do not exist"<<std::endl;
            return false;
        }
        e.setWeight(1);
        edges.push_back(&e);
        nodes[getIndexNode(e.getStartNode())]->incrementDegree();
        //nodes[getIndexNode(e.getEndNode())]->incrementDegree();
        sortEdgeVector();
        return true;
    }else {
        std::cout << "Edge already exists, duplicates are not allowed in bi-direcitonal graphs";
        return false;
    }
}

bool ADirectional_Graph::removeEdge(Edge &e) {

    int startId = e.getStartNode();
    int endId = e.getEndNode();

    if (searchEdge(e)) {
        for (unsigned int i = 0; i < edges.size(); i++) {
            if (edges.at(i)->getStartNode() == startId && edges.at(i)->getEndNode() == endId) {
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
    for (Node *n : nodes) {
        if (n->getId() == v.getId())
            return true;
    }
    return false;
}

bool ADirectional_Graph::searchNode(int id) {
    for (Node *n : nodes) {
        //std::cout<<"debug comparing "<<n->getId() << " and " << id << std::endl;
        if (n->getId() == id);
            return true;
    }
    return false;
}

bool ADirectional_Graph::searchEdge(const Edge &e) {
    //go through all edges in vector and compare the weight.
    //If they have the same weight, check their start and end ID
    //if all three values are the same, they're identical
    for (Edge *ed : edges) {
        if (ed->getWeight() == e.getWeight()) {
            //check the start and end points
            if (ed->getStartNode() == e.getStartNode() && ed->getEndNode() == e.getEndNode())
                return true;
        }
    }
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
    for (unsigned int i = 0; i < nodes.size(); i++) {
        if (nodes[i]->getId() == v.getId())
            return i;
    }
    return -1;
}

int ADirectional_Graph::getIndexNode(int id) {
    for (unsigned int i = 0; i < nodes.size(); i++) {
        if (nodes[i]->getId() == id)
            return i;
    }
    return -1;
}

int ADirectional_Graph::getIndexEgde(Edge &e) {
    for (unsigned int i = 0; i < nodes.size(); i++) {
        if (edges[i]->getStartNode() == e.getStartNode() && edges[i]->getEndNode() == e.getEndNode())
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


void ADirectional_Graph::pathFinder(const Edge* e) {

}

void ADirectional_Graph::pathFinder(const Node* e) {

}




void ADirectional_Graph::sortNodeVector() {
    //preform insertion sort based on node ID
    /*int j;
    Node *tmp;

    for (int i = 0; i < nodes.size(); i++) {
        j = i;

        while (j > 0 && nodes[j] > nodes[j - 1]) {
            tmp = nodes[j];
            nodes[j] = nodes[j - 1];
            nodes[j - 1] = tmp;
            j--;
        }
    }*/

    std::sort(nodes.begin(), nodes.end(), CompareNodes());
}


void ADirectional_Graph::sortEdgeVector() {
    std::sort(edges.begin(),edges.end(),CompareEdges());
}

void ADirectional_Graph::printGraphEdges(){
    for(Edge *e: edges){
        std::cout<<e->getStartNode()<<"->"<<e->getEndNode()<<std::endl;
    }
}

void ADirectional_Graph::printGraphNodes(){
    for(Node *node: nodes){
        std::cout<<node->getId()<<std::endl;
    }
}



