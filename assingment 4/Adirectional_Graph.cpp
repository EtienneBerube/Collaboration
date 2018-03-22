//
// Created by Etienne on 17/03/2018.
//

#include <algorithm>
#include <stack>
#include "Adirectional_Graph.h"
#include "Node.h"
#include "Edge.h"
#include <sstream>
using namespace std;

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
    if(e.getStartNode() > e.getEndNode()){
        std::cout<<"A node with a bigger ID cannot be connected with a node wit ha smaller ID"<<std::endl;
    }else if (!searchEdge(e)) {
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

    for (int i = 0; i < length; i++)
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
        if (n->getId() == id)
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
    pathFinder(&v);
}

void ADirectional_Graph::display(Node &e) const {
    pathFinder(&e);

}

//Adjencency Matrix
void ADirectional_Graph::display() const {

}
//NOT DONE
std::string ADirectional_Graph::toString()  {
    std::string output;
    std::stack<Edge*> pathStack;
    std::stack<int> currentDegreeStack;

    bool notPath = false;

    for(unsigned int i = 0; i < edges.size();++i){
        //source
        notPath = false;
        pathStack.push(edges[i]);
        currentDegreeStack.push(0);
        //std::cout<<"********************Starts with: "<<pathStack.top()->getStartNode()<<"->"<<pathStack.top()->getEndNode()<<std::endl;
        while(!notPath) {
            /*std::cout<<"inside While"<<std::endl;
            std::cout<<"Stack top edge: "<<pathStack.top()->getStartNode()<<"->"<<pathStack.top()->getEndNode()<<std::endl;
            std::cout<<"Stack degree top: "<<currentDegreeStack.top()<<std::endl;*/
            if( pathStack.empty() && currentDegreeStack.empty()) {
                //std::cout << "woupsi" << std::endl;
                notPath = true;
                break;
            }else if(currentDegreeStack.top()!= nodes[getIndexNode(pathStack.top()->getEndNode())]->getdegree()){
                //std::cout<<"inside go deeper"<<std::endl;
                pathStack.push(edges[getIndexEdgeStartWith(pathStack.top()->getEndNode())+currentDegreeStack.top()]);
                currentDegreeStack.push(0);

            }else if(currentDegreeStack.top() == nodes[getIndexNode(pathStack.top()->getEndNode())]->getdegree()){
                //std::cout<<"inside abort"<<std::endl;

                output+=stackToString(pathStack);
                pathStack.pop();
                currentDegreeStack.pop();

                if(!pathStack.empty() && !currentDegreeStack.empty()) {
                    int temp = currentDegreeStack.top();
                    temp++;
                    currentDegreeStack.pop();
                    currentDegreeStack.push(temp);
                }
            }else{
                //std::cout<<"Test"<<std::endl;
            }
        }
    }
    /*if(notPath){
        std::cout<<"graph is empty"<<std::endl;
        return nullptr;
    }else{*/
        return output;
   // }

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


int ADirectional_Graph::getIndexNode(Node &v) const{
    for (unsigned int i = 0; i < nodes.size(); i++) {
        if (nodes[i]->getId() == v.getId())
            return i;
    }
    return -1;
}

int ADirectional_Graph::getIndexNode(int id) const{
    for (unsigned int i = 0; i < nodes.size(); i++) {
        if (nodes[i]->getId() == id)
            return i;
    }
    return -1;
}

int ADirectional_Graph::getIndexEgde(Edge &e) const {
    for (unsigned int i = 0; i < nodes.size(); i++) {
        if (edges[i]->getStartNode() == e.getStartNode() && edges[i]->getEndNode() == e.getEndNode())
            return i;
    }
    return -1;;
}

int ADirectional_Graph::getIndexEgde(int id) const{ //Might Delete
    for (unsigned int i = 0; i < edges.size(); i++) {
        if (edges[i]->getStartNode() == id && edges[i]->getEndNode() == id)
            return i;
    }
    return -1;
}

int ADirectional_Graph::getIndexEdgeStartWith(int id) const{
    for (unsigned int i = 0; i < edges.size(); i++) {
        if (edges[i]->getStartNode() == id)
            return i;
    }
    return -1;
}

void ADirectional_Graph::pathFinder(const Edge* e) const {
    std::stack<Edge*> pathStack;
    std::stack<int> currentDegreeStack;

    bool pathFound = false;
    bool notPath = false;

    for(unsigned int i = 0; i < edges.size();++i){
        //source
        notPath = false;
        pathStack.push(edges[i]);
        currentDegreeStack.push(0);
        //std::cout<<"********************Starts with: "<<pathStack.top()->getStartNode()<<"->"<<pathStack.top()->getEndNode()<<std::endl;
        while(!pathFound&&!notPath) {
            /*std::cout<<"inside While"<<std::endl;
            std::cout<<"Stack top edge: "<<pathStack.top()->getStartNode()<<"->"<<pathStack.top()->getEndNode()<<std::endl;
            std::cout<<"Stack degree top: "<<currentDegreeStack.top()<<std::endl;*/
            if( pathStack.empty() && currentDegreeStack.empty()) {
                //std::cout << "woupsi" << std::endl;
                notPath = true;
                break;
            }else if(pathStack.top() == e){
                //std::cout<<"inside path found"<<std::endl;
                pathFound = true;
            }else if(currentDegreeStack.top()!= nodes[getIndexNode(pathStack.top()->getEndNode())]->getdegree()){
                //std::cout<<"inside go deeper"<<std::endl;
                pathStack.push(edges[getIndexEdgeStartWith(pathStack.top()->getEndNode())+currentDegreeStack.top()]);
                currentDegreeStack.push(0);

            }else if(currentDegreeStack.top() == nodes[getIndexNode(pathStack.top()->getEndNode())]->getdegree()){
                //std::cout<<"inside abort"<<std::endl;
                pathStack.pop();
                currentDegreeStack.pop();

                if(!pathStack.empty() && !currentDegreeStack.empty()) {
                    int temp = currentDegreeStack.top();
                    temp++;
                    currentDegreeStack.pop();
                    currentDegreeStack.push(temp);
                }
            }else{
                //std::cout<<"Test"<<std::endl;
            }
        }
        if(pathFound)
            break;
    }
    if(!pathFound || notPath){
        std::cout<<"No possible path using edge "<<e<<"it may not exist"<<std::endl;
        return;
    }else{
        std::vector<Edge*> buffer;
        while(!pathStack.empty()){
            Edge *temp = pathStack.top();
            buffer.push_back(temp);
            pathStack.pop();
        }
        std::cout<<"Path using edge: "<<*e<<std::endl;

        for(size_t i = buffer.size()-1;i>=0&&i<buffer.size();--i)
            std::cout<<buffer[i]->getStartNode()<<"->"<<buffer[i]->getEndNode()<<";";
        std::cout<<std::endl;
    }
}

void ADirectional_Graph::pathFinder(const Node* n) const {
    std::stack<Edge*> pathStack;
    std::stack<int> currentDegreeStack;
    std::vector<int> visitedNodes;

    bool pathFound = false;
    bool notPath = false;

    for(unsigned int i = 0; i < edges.size();++i){
        //source
        visitedNodes.clear();

        notPath = false;

        pathStack.push(edges[i]);

        visitedNodes.push_back(edges[i]->getStartNode());
        visitedNodes.push_back(edges[i]->getEndNode());

        currentDegreeStack.push(0);

        //std::cout<<"********************Starts with: "<<pathStack.top()->getStartNode()<<"->"<<pathStack.top()->getEndNode()<<std::endl;
        while(!pathFound&&!notPath) {
            /*std::cout<<"inside While"<<std::endl;
            std::cout<<"Stack top edge: "<<pathStack.top()->getStartNode()<<"->"<<pathStack.top()->getEndNode()<<std::endl;
            std::cout<<"Stack degree top: "<<currentDegreeStack.top()<<std::endl;*/
            if( pathStack.empty() && currentDegreeStack.empty()) {
                //std::cout << "woupsi" << std::endl;
                notPath = true;
                break;
            }else if(pathStack.top()->getEndNode() == n->getId()){
                //std::cout<<"inside path found"<<std::endl;
                pathFound = true;
            }else if(currentDegreeStack.top()!= nodes[getIndexNode(pathStack.top()->getEndNode())]->getdegree()){//<----- crashes
                //std::cout<<"inside go deeper"<<std::endl;

                    pathStack.push(
                            edges[getIndexEdgeStartWith(pathStack.top()->getEndNode()) + currentDegreeStack.top()]);
                    visitedNodes.push_back(pathStack.top()->getEndNode() + currentDegreeStack.top());
                    currentDegreeStack.push(0);


            }else if(currentDegreeStack.top() == nodes[getIndexNode(pathStack.top()->getEndNode())]->getdegree()){
                //std::cout<<"inside abort"<<std::endl;
                pathStack.pop();
                currentDegreeStack.pop();

                if(!pathStack.empty() && !currentDegreeStack.empty()) {
                    int temp = currentDegreeStack.top();
                    temp++;
                    currentDegreeStack.pop();
                    currentDegreeStack.push(temp);
                }
            }else{
                //std::cout<<"Test"<<std::endl;
            }
        }
        if(pathFound)
            break;
    }
    if(!pathFound || notPath){
        std::cout<<"No possible path to node#"<<n->getId()<<". It might be orphan"<<std::endl;
        return;
    }else{
        std::vector<Edge*> buffer;
        while(!pathStack.empty()){
            Edge *temp = pathStack.top();
            buffer.push_back(temp);
            pathStack.pop();
        }
        std::cout<<"Path up to node: "<<n->getId()<<std::endl;

        for(size_t i = buffer.size()-1;i>=0&&i<buffer.size();--i)
            std::cout<<buffer[i]->getStartNode()<<"->"<<buffer[i]->getEndNode()<<";";
        std::cout<<std::endl;
    }


}




void ADirectional_Graph::sortNodeVector() {
    std::sort(nodes.begin(), nodes.end(), CompareNodes());
}


void ADirectional_Graph::sortEdgeVector() {
    std::sort(edges.begin(),edges.end(),CompareEdges());
}

void ADirectional_Graph::printGraphEdges(){
    std::cout<<"from -> to : weight"<<std::endl;
    for(Edge *e: edges){
        std::cout<<e->getStartNode()<<"->"<<e->getEndNode()<<":" << e->getWeight() <<std::endl;
    }
    std::cout<<std::endl;
}

void ADirectional_Graph::printGraphNodes(){
    std::cout<<"ID: Degree out"<<std::endl;
    for(Node *n : nodes)
        std::cout<<n->getId()<<": " << n->getdegree()<<std::endl;
    std::cout<<std::endl;
}



ADirectional_Graph::~ADirectional_Graph() {
    for(Node* n: nodes)
        delete n;
    for(Edge* e: edges)
        delete e;
}

std::string ADirectional_Graph::stackToString(std::stack<Edge *> &stack) {
    std::vector<Edge*> buffer;
    std::string output;
    while(!stack.empty()){
        Edge *temp = stack.top();
        buffer.push_back(temp);
        stack.pop();
    }

    for(size_t i = buffer.size()-1;i>=0&&i<buffer.size();--i) {
        stack.push(buffer[i]);
        output += (std::string("") + to_string(buffer[i]->getStartNode()) + std::string("->") + to_string(buffer[i]->getEndNode()) + std::string(";"));
    }
    return output+"\n";

}

bool ADirectional_Graph::hasBeenVisited(int id, std::vector<int>& vector) const {
    bool isVisited = false;
    for(int i: vector)
        if(i == id)
            return true;
    return false;
}






