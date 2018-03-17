//
// Created by Etienne on 17/03/2018.
//

#ifndef ASSINGMENT_4_A_DIRECTIONAL_GRAPH_H
#define ASSINGMENT_4_A_DIRECTIONAL_GRAPH_H


#include "Graph.h"

class A_Directional_Graph: public Graph {
public:
    bool addNode(Node &v) override;

    bool removeNode(Node &v) override;

    bool addEdge(Edge &e) override;

    bool remove(Edge &e) override;

    bool removeMultipleEdges(Edge *e) override;

    bool searchNode(const Node &v) override;

    bool searchEdge(const Edge &e) override;

    void display(Edge &v) const override;

    void display(Node &e) const override;

    void display() const override;

    std::string toString() const override;

    bool clean() override;
};


#endif //ASSINGMENT_4_A_DIRECTIONAL_GRAPH_H
