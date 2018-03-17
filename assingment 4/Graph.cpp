//
// Created by Etienne on 17/03/2018.
//

#include "Graph.h"
#include "Edge.h"

Graph &Graph::operator++() {
    for(Edge* e: edges)
        e->incrementWeight();
    return *this;
}

Graph::Graph() {

}

Graph::~Graph() {
    for (unsigned int i = 0; i < nodes.size(); ++i) {
        delete nodes[i];
        nodes.erase(nodes.begin() + i);
    }

    for (unsigned int i = 0; i < edges.size(); ++i) {
        delete edges[i];
        edges.erase(edges.begin() + i);
    }
}
