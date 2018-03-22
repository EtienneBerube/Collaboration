//
// Created by Etienne on 17/03/2018.
//

#ifndef ASSINGMENT_4_A_DIRECTIONAL_GRAPH_H
#define ASSINGMENT_4_A_DIRECTIONAL_GRAPH_H


#include "Graph.h"
#include <stack>
#include <ostream>

class ADirectional_Graph: public Graph {
public:
    ADirectional_Graph();
    ADirectional_Graph(std::vector<Node *>&, std::vector<Edge*>&);

    ~ADirectional_Graph();
    bool addNode(Node &v);

    bool removeNode(Node &v);

    bool addEdge(Edge &e);

    bool removeEdge(Edge &e);

    bool removeMultipleEdges(Edge *e, int length);

    bool searchNode(const Node &v);

    bool searchEdge(const Edge &e);

    void display(Edge &v) const;

    void display(Node &e) const;

    void display() const;

    //Needed to turn toString non-const
    std::string toString();

    bool clean() override;

    int getIndexNode(int id) const;

    int getIndexEgde(int id) const;

    void printGraphEdges();

    void printGraphNodes();

    friend std::ostream &operator<<(std::ostream &os, ADirectional_Graph &graph);

    ADirectional_Graph& operator++();

    ADirectional_Graph& operator=(const ADirectional_Graph &rhs);

    ADirectional_Graph operator+(const ADirectional_Graph &rhs);

    bool operator<(const ADirectional_Graph &rhs) const;

    bool operator>(const ADirectional_Graph &rhs) const;

    bool operator==(const ADirectional_Graph &rhs) const;

    bool operator!=(const ADirectional_Graph &rhs) const;


private:
    void pathFinder(const Edge *e) const;
    void pathFinder(const Node *e) const;
	void sortNodeVector();
	void sortEdgeVector();
    int getIndexNode(Node& n) const;
    int getIndexEgde(Edge& e) const;
    int getIndexEdgeStartWith(int id) const;
    bool searchNode(int id);
    std::string stackToString(std::stack<Edge *> &stack);
    bool hasBeenVisited(int id, std::vector<int>& vector) const;


};


#endif //ASSINGMENT_4_A_DIRECTIONAL_GRAPH_H
