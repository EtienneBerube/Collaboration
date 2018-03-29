/*
 * COEN 244 Assignment 4
 * Etienne Berube: 40052212
 * Braldey Walsh: 40063018
 */

#ifndef ASSINGMENT_4_VERTEX_H
#define ASSINGMENT_4_VERTEX_H

#include <iostream>
#include <vector>

class Vertex;

class Node {
private:
    int id;

    int degree;

public:

    Node(int id);
    Node(int id, int degree);
    Node(const Node& node);
    int getId() const;

    void setId(int id);

    inline int getdegree() const {return degree;}

    inline void incrementDegree(){degree++;}

    inline void decrementDegree(){degree--;}

    bool operator==(const Node &rhs) const;

    bool operator!=(const Node &rhs) const;
};


#endif //ASSINGMENT_4_VERTEX_H
