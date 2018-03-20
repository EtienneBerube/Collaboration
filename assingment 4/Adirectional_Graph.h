//
// Created by Etienne on 17/03/2018.
//

#ifndef ASSINGMENT_4_A_DIRECTIONAL_GRAPH_H
#define ASSINGMENT_4_A_DIRECTIONAL_GRAPH_H


#include "Graph.h"

class ADirectional_Graph: public Graph {
public:
    bool addNode(Node &v);

    bool removeNode(Node &v);

    bool addEdge(Edge &e);

    bool removeEdge(Edge &e);

    bool removeMultipleEdges(Edge *e, int length);

    int getIndexNode(Node& n);

    int getIndexEgde(Edge& e);

    bool searchNode(const Node &v);

    bool searchEdge(const Edge &e);

    void display(Edge &v) const;

    void display(Node &e) const;

    void display() const;

    std::string toString() const;

    bool clean() override;

    int getIndexNode(int id);

    int getIndexEgde(int id);

    void printGraphEdges();

    void printGraphNodes();

private:
	void sortNodeVector();
	void sortEdgeVector();
    bool searchNode(int id);
    void pathFinder(const Edge *e);
    void pathFinder(const Node *e);
};


#endif //ASSINGMENT_4_A_DIRECTIONAL_GRAPH_H
