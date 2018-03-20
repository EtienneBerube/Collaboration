//
// Created by Etienne on 17/03/2018.
//

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
    int getId() const;

    void setId(int id);

    inline void incrementDegree(){degree++;}

    inline void decrementDegree(){degree--;}
};


#endif //ASSINGMENT_4_VERTEX_H
