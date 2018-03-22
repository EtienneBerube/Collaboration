//
// Created by Etienne on 17/03/2018.
//

#ifndef ASSINGMENT_4_A_DIRECTIONAL_GRAPH_H
#define ASSINGMENT_4_A_DIRECTIONAL_GRAPH_H


#include "Graph.h"

class ADirectional_Graph: public Graph {
public:

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

    std::string toString() const;

    bool clean() override;

    int getIndexNode(int id) const;

    int getIndexEgde(int id) const;

    void printGraphEdges();

    void printGraphNodes();

    void printDegreesDebug();


private:
    void pathFinder(const Edge *e) const;
    void pathFinder(const Node *e) const;
	void sortNodeVector();
	void sortEdgeVector();
    int getIndexNode(Node& n) const;
    int getIndexEgde(Edge& e) const;
    int getIndexEdgeStartWith(int id) const;
    bool searchNode(int id);

};


#endif //ASSINGMENT_4_A_DIRECTIONAL_GRAPH_H
