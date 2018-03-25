//
// Created by Etienne on 17/03/2018.
//

#include <algorithm>
#include <stack>
#include "Adirectional_Graph.h"
#include "Node.h"
#include "Edge.h"
#include <sstream>
//using namespace std;

//*****************************COMPARATOR*****************************
//will be used to sort the edges by their starting node's IDs
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

//Will be used to sort nodes by increasing ID
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

//Adds a node to the graph
bool ADirectional_Graph::addNode(Node &v) {

    if (!searchNode(v)) {
        nodes.push_back(&v);
        sortNodeVector();
        return true;
    }
    std::cout << "Node already exists, Change ID to add node to graph";
    return false;

}

//Removes a ndoe from the graph
bool ADirectional_Graph::removeNode(Node &v) {
    int currentId = v.getId();

    if (!searchNode(v))
        return false;

    //Removes all the edges that are connected to this node
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

//Adds an edge to the graph
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

//Remove an edge from the graph
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

//Removes multiple edges from the graph
bool ADirectional_Graph::removeMultipleEdges(Edge *e, int length) {

    for (int i = 0; i < length; i++)
        removeEdge(e[i]);
    delete[] e;


    return true;
}

//Returns true if the graph has the specified node
bool ADirectional_Graph::searchNode(const Node &v) {
    for (Node *n : nodes) {
        if (n->getId() == v.getId())
            return true;
    }
    return false;
}

//Returns true if the graph has a node with this id
bool ADirectional_Graph::searchNode(int id) {
    for (Node *n : nodes) {
        if (n->getId() == id)
            return true;
    }
    return false;
}

//Returns true if the graph contains a specific edge
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
//Displays the first possible path containing this edge
void ADirectional_Graph::display(Edge &v) const {
    pathFinder(&v);
}

//Displays the first possible path that contains this node
void ADirectional_Graph::display(Node &e) const {
    pathFinder(&e);

}

//Adjencency Matrix
void ADirectional_Graph::display() const {

	int** matrix = new int*[nodes.size()];
	for (unsigned int i = 0; i < nodes.size(); i++)
        matrix[i] = new int(nodes.size());


    //TODO INTIALIZE TO ZERO
	for (unsigned int i = 0; i < nodes.size(); i++)
	{
		for (unsigned int j = 0; j < nodes.size(); j++)
			matrix[i][j] = 0;
	}

	
	//first line will be a whitespace followed by the ID's of the numbers
	std::cout << "  ";
	//start by printing the first row
	/*for (unsigned int i = 0; i < nodes.size(); i++)
		std::cout << nodes.at(i)->getId() ;
	cout << endl;
	*/

    //print first row with ID's
	for (size_t i = 0; i < nodes.size(); i++)
	{
		matrix[0][i + 1] = nodes[i]->getId();
		cout << matrix[0][i + 1];
	}
	cout << endl;
	
	//print the rest of the matrix
	for (unsigned int i = 0; i < edges.size(); i++)
	{
		int from = edges[i]->getStartNode();
        int to = edges[i]->getEndNode();

        int indexRow = 0;
        int indexCol = 0;

        for(unsigned int j = 0; j < nodes.size(); j++)
		{
            if(matrix[i][j] == to)
                indexCol = to;
        }

        for(unsigned int j = 0; j < nodes.size(); j++)
		{
            if(matrix[j][i] == from)
                indexRow = from;
        }
		if(!indexRow && !indexCol)
			matrix[indexRow][indexCol] = 1;


	}

<<<<<<< HEAD
	//print the contents of the matrix
	for (unsigned int i = 0; i < nodes.size(); i++)
	{
		cout << nodes.at(i)->getId() << " "; //first print the ID of the row
		for (unsigned int j = 0; j < nodes.size(); j++)
			cout << matrix[i][j];
		cout << endl; 
	}





	////print a white space in the top left corner of the matrix
	//std::cout << " ";
	////start by printing the first row
	//for (unsigned int i = 0; i < nodes.size(); i++)
	//	std::cout << nodes.at(i)->getId() ;
	//cout << endl;
	////print rest of rows
	//for (unsigned int i = 0; i < nodes.size(); i++)
	//{
	//	//print the number of the row
	//	std::cout << nodes.at(i)->getId();

	//	//check to see if the current row element is connected to the current collumn
	//	for (unsigned int j = 0; j < nodes.size(); j++)
	//	{
	//		if (edges.at(i)->getEndNode() == edges.at(j)->getStartNode())
	//			cout << "1";
	//		else
	//			cout << "0";
	//	}
	//	cout << endl;
	//}

=======
>>>>>>> 6ed3fafd13019914195d838f1976f648efadfc7c
}
//Prints all possible paths associated with this graph (paths may be of length 1 to the longest path of the graph)
std::string ADirectional_Graph::toString()  {
    std::string output;
    std::stack<Edge*> pathStack;
    std::stack<int> currentDegreeStack;

    bool notPath = false;
    //Path will start at each possible node within the possible edges (they will not start at orphan nodes)

    for(unsigned int i = 0; i < edges.size();++i){
        //source
        notPath = false;
        pathStack.push(edges[i]);
        currentDegreeStack.push(0);

        while(!notPath) {
           //Breaks if the stack is empty
            if( pathStack.empty() && currentDegreeStack.empty()) {

                notPath = true;
                break;

            //Goes deeper if the node is not the one we are looking for
            }else if(currentDegreeStack.top()!= nodes[getIndexNode(pathStack.top()->getEndNode())]->getdegree()){

                pathStack.push(edges[getIndexEdgeStartWith(pathStack.top()->getEndNode())+currentDegreeStack.top()]);
                currentDegreeStack.push(0);

                //returns back one level
            }else if(currentDegreeStack.top() == nodes[getIndexNode(pathStack.top()->getEndNode())]->getdegree()){


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
    return output;


}

//Deletes every node and edges from the graph
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


//Returns the index of a node in the vector<Node *>
int ADirectional_Graph::getIndexNode(Node &v) const{
    for (unsigned int i = 0; i < nodes.size(); i++) {
        if (nodes[i]->getId() == v.getId())
            return i;
    }
    return -1;
}

//Returns the index of a node in the vector<Node *>
int ADirectional_Graph::getIndexNode(int id) const{
    for (unsigned int i = 0; i < nodes.size(); i++) {
        if (nodes[i]->getId() == id)
            return i;
    }
    return -1;
}
//Returns the index of an edge in the vector<Edge *>
int ADirectional_Graph::getIndexEgde(Edge &e) const {
    for (unsigned int i = 0; i < nodes.size(); i++) {
        if (edges[i]->getStartNode() == e.getStartNode() && edges[i]->getEndNode() == e.getEndNode())
            return i;
    }
    return -1;;
}
//Returns the index of an edge in the vector<Edge *>
int ADirectional_Graph::getIndexEgde(int id) const{ //Might Delete
    for (unsigned int i = 0; i < edges.size(); i++) {
        if (edges[i]->getStartNode() == id && edges[i]->getEndNode() == id)
            return i;
    }
    return -1;
}
//Gets the index of the first edge that has the corresponding id for its starting edge
int ADirectional_Graph::getIndexEdgeStartWith(int id) const{
    for (unsigned int i = 0; i < edges.size(); i++) {
        if (edges[i]->getStartNode() == id)
            return i;
    }
    return -1;
}

//Finds the path that contains such an edge
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
            if( pathStack.empty() && currentDegreeStack.empty()) {
                notPath = true;
                break;

            }else if(pathStack.top() == e){

                pathFound = true;
            }else if(currentDegreeStack.top()!= nodes[getIndexNode(pathStack.top()->getEndNode())]->getdegree()){
                pathStack.push(edges[getIndexEdgeStartWith(pathStack.top()->getEndNode())+currentDegreeStack.top()]);
                currentDegreeStack.push(0);

            }else if(currentDegreeStack.top() == nodes[getIndexNode(pathStack.top()->getEndNode())]->getdegree()){
                pathStack.pop();
                currentDegreeStack.pop();

                if(!pathStack.empty() && !currentDegreeStack.empty()) {
                    int temp = currentDegreeStack.top();
                    temp++;
                    currentDegreeStack.pop();
                    currentDegreeStack.push(temp);
                }
            }else{
                //DEBUGGING PURPOSE - SHOULD NOT BE USED
            }
        }
        if(pathFound)
            break;
    }
    //Prints error if no path found
    if(!pathFound || notPath){
        std::cout<<"No possible path using edge "<<e<<"it may not exist"<<std::endl;
        return;
    }else{
        //Prints path
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

//Finds the path that contains such a Node
//Refer to the previous function for documentation (pathFinder(Edge* e))
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
            if( pathStack.empty() && currentDegreeStack.empty()) {
                notPath = true;
                break;

            }else if(pathStack.top()->getEndNode() == n->getId()){
                pathFound = true;

            }else if(currentDegreeStack.top()!= nodes[getIndexNode(pathStack.top()->getEndNode())]->getdegree()){//<----- crashes

                    pathStack.push(
                            edges[getIndexEdgeStartWith(pathStack.top()->getEndNode()) + currentDegreeStack.top()]);
                    visitedNodes.push_back(pathStack.top()->getEndNode() + currentDegreeStack.top());
                    currentDegreeStack.push(0);


            }else if(currentDegreeStack.top() == nodes[getIndexNode(pathStack.top()->getEndNode())]->getdegree()){
                pathStack.pop();
                currentDegreeStack.pop();

                if(!pathStack.empty() && !currentDegreeStack.empty()) {
                    int temp = currentDegreeStack.top();
                    temp++;
                    currentDegreeStack.pop();
                    currentDegreeStack.push(temp);
                }
            }else{
                //Should not be used - Debugging only
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



//Sorts all the Nodes within the vector
void ADirectional_Graph::sortNodeVector() {
    std::sort(nodes.begin(), nodes.end(), CompareNodes());
}

//Sorts all the edges within the vector
void ADirectional_Graph::sortEdgeVector() {
    std::sort(edges.begin(),edges.end(),CompareEdges());
}

//Prints all the edges and their weights
void ADirectional_Graph::printGraphEdges(){
    std::cout<<"from -> to : weight"<<std::endl;
    for(Edge *e: edges){
        std::cout<<e->getStartNode()<<"->"<<e->getEndNode()<<":" << e->getWeight() <<std::endl;
    }
    std::cout<<std::endl;
}

//Prints all the nodes and their attributes
void ADirectional_Graph::printGraphNodes(){
    std::cout<<"ID: Degree out"<<std::endl;
    for(Node *n : nodes)
        std::cout<<n->getId()<<": " << n->getdegree()<<std::endl;
    std::cout<<std::endl;
}


//Destructor
ADirectional_Graph::~ADirectional_Graph() {
    for(Node* n: nodes)
        delete n;
    for(Edge* e: edges)
        delete e;
}

//Transfers a stack to a string representation of it
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


ADirectional_Graph::ADirectional_Graph() {

}

ADirectional_Graph::ADirectional_Graph(std::vector<Node *> &n, std::vector<Edge *> &e) : Graph(n,e){

}

//**********************************OPERATOR OVERLOADING************************************************
std::ostream &operator<<(std::ostream &os, ADirectional_Graph &graph) {
    os << graph.toString();
    return os;
}
//******************************************************************************************************
bool ADirectional_Graph::operator==(const ADirectional_Graph &rhs) const {
    if(edges.size() != rhs.getEdges().size() || nodes.size() != rhs.getNode().size())
        return false;

    std::vector<Edge*> tempEdge = rhs.getEdges();
    for(unsigned int i = 0; i < edges.size(); i++){
        std::cout<<edges[i]->getStartNode()<<"->"<<edges[i]->getEndNode()<<":"<<tempEdge[i]->getStartNode()<<"->"<<tempEdge[i]->getEndNode()<<std::endl;
        if(edges[i]->getStartNode() != tempEdge[i]->getStartNode() ||
                edges[i]->getEndNode() != tempEdge[i]->getEndNode() ||
                edges[i]->getWeight() != tempEdge[i]->getWeight())
            return false;
    }
    std::vector<Node*> tempNode = rhs.getNode();
    for(unsigned int i = 0; i < nodes.size(); i++){
        if(nodes[i]->getId() != tempNode[i]->getId() || nodes[i]->getdegree() != tempNode[i]->getdegree())
            return false;
    }
    return true;
}

bool ADirectional_Graph::operator!=(const ADirectional_Graph &rhs) const {
    return !(rhs == *this);
}

bool ADirectional_Graph::operator<(const ADirectional_Graph &rhs) const {
    int weight1 =0;
    int weight2 =0;

    for(Edge* e: edges){
        weight1 += e->getWeight();
    }

    for(Edge* e: rhs.getEdges()){
        weight2 += e->getWeight();
    }
    return weight1 < weight2;


}

bool ADirectional_Graph::operator>(const ADirectional_Graph &rhs) const {
    return rhs < *this;
}


ADirectional_Graph &ADirectional_Graph::operator++() {
    for(Edge* e: edges)
        e->incrementWeight();
    return *this;
}

ADirectional_Graph &ADirectional_Graph::operator=(const ADirectional_Graph &rhs) {
    for(Edge* e: rhs.getEdges()){
        edges.push_back(new Edge(e->getStartNode(), e->getEndNode(), e->getWeight()));
    }

    for(Node* n: rhs.getNode()){
        nodes.push_back(new Node(n->getId(),n->getdegree()));
    }

    return *this;
}


ADirectional_Graph ADirectional_Graph::operator+(const ADirectional_Graph &rhs) {
    std::vector<Node*> tempNodes;
    std::vector<Edge*> tempEdges;
	std::vector<Node*> tempNodes2;
	std::vector<Edge*> tempEdges2;

    //Needs to created multiple temporary vectors to merge the attributes of the graphs

    for(Edge* e: rhs.getEdges()){
        tempEdges.push_back(new Edge(e->getStartNode(), e->getEndNode(), e->getWeight()));
    }

    for(Edge* e: edges){
        tempEdges2.push_back(new Edge(e->getStartNode(), e->getEndNode(), e->getWeight()));
    }


	if (!tempEdges.empty() || !edges.empty()){
		for (Edge* e2 : edges)
		{
			for (Edge* e3 : tempEdges)
				if (e2->getStartNode() != e3->getStartNode() ||	e2->getEndNode() != e3->getEndNode() ||	e2->getWeight() != e3->getWeight())
					tempEdges.push_back(new Edge(e2->getStartNode(), e2->getEndNode(), e2->getWeight()));
		}
    }else{
        tempEdges.clear();
        for(Edge* e: rhs.getEdges()){
            tempEdges.push_back(new Edge(e->getStartNode(), e->getEndNode(), e->getWeight()));
        }

        for(Edge* e: edges){
            tempEdges.push_back(new Edge(e->getStartNode(), e->getEndNode(), e->getWeight()));
        }
    }


    for(Node* n: rhs.getNode()){
        tempNodes.push_back(new Node(n->getId(),n->getdegree()));
    }

    if(!tempEdges.empty() || !edges.empty()) {


        for (unsigned int i = 0; i < nodes.size(); i++) {
            bool needTransfer = false;
            for (unsigned int j = 0; j < tempNodes.size(); j++) {
                if (nodes[i]->getId() != tempNodes[j]->getId() ||
                    nodes[i]->getdegree() != tempNodes[j]->getdegree()) //<---- broken
                    needTransfer = true;
            }
            if (needTransfer) {
                tempNodes2.push_back(new Node(nodes.at(i)->getId(), nodes.at(i)->getdegree()));
            }
        }
    }else{
        tempNodes.clear();
        for(Node* n: rhs.getNode()){
            tempNodes.push_back(new Node(n->getId(),n->getdegree()));
        }

        for(Node* n: nodes){
            tempNodes.push_back(new Node(n->getId(),n->getdegree()));
        }
    }
<<<<<<< HEAD
	//add tempNodes2 to tempNotes
	for (unsigned int i = 0; i < tempNodes2.size(); i++)
=======
	//Merges the temporary vectors to get the final one
	for (int i = 0; i < tempNodes2.size(); i++)
>>>>>>> 6ed3fafd13019914195d838f1976f648efadfc7c
		tempNodes.push_back(tempNodes2[i]);

    for (unsigned int i = 0; i < tempEdges2.size(); i++)
		tempEdges.push_back(tempEdges2[i]);

    //Sorts the resulting vectors

    std::sort(tempNodes.begin(), tempNodes.end(), CompareNodes());
    std::sort(tempEdges.begin(), tempEdges.end(), CompareEdges());


    return ADirectional_Graph(tempNodes,tempEdges);
}








