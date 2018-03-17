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
