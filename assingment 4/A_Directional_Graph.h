//
// Created by Etienne on 17/03/2018.
//

#ifndef ASSINGMENT_4_A_DIRECTIONAL_GRAPH_H
#define ASSINGMENT_4_A_DIRECTIONAL_GRAPH_H


#include "Graph.h"

class A_Directional_Graph: public Graph {
public:
    bool addVertex(Vertex &v) override;

    bool removeVertex(Vertex &v) override;

    bool addEdge(Node &e) override;

    bool remove(Node &e) override;

    bool searchVertex(const Vertex &v) override;

    bool searchEdge(const Node &e) override;

    void display(Vertex &v) const override;

    void display(Node &e) const override;

    void display() const override;

    std::string toString() const override;

    bool clean() override;
};


#endif //ASSINGMENT_4_A_DIRECTIONAL_GRAPH_H
