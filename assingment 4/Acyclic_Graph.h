/*
 * COEN 244 Assignment 4
 * Etienne Berube: 40052212
 * Braldey Walsh: 40063018
 */

#ifndef ASSINGMENT_4_A_CYCLIC_GRAPH_H
#define ASSINGMENT_4_A_CYLCIC_GRAPH_H


#include "Graph.h"
#include <stack>
#include <ostream>

class Acyclic_Graph: public Graph {
public:
    Acyclic_Graph();
    Acyclic_Graph(std::vector<Node *>&, std::vector<Edge*>&);

    ~Acyclic_Graph();
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

    friend std::ostream &operator<<(std::ostream &os, Acyclic_Graph &graph);

    Acyclic_Graph& operator++();

    Acyclic_Graph& operator=(const Acyclic_Graph &rhs);

    Acyclic_Graph operator+(const Acyclic_Graph &rhs);

    bool operator<(const Acyclic_Graph &rhs) const;

    bool operator>(const Acyclic_Graph &rhs) const;

    bool operator==(const Acyclic_Graph &rhs) const;

    bool operator!=(const Acyclic_Graph &rhs) const;


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
	int getRefrenceFromID(int* matrix, int size, int ID) const;


};


#endif //ASSINGMENT_4_A_CYCLIC_GRAPH_H
