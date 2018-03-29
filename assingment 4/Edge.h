/*
 * COEN 244 Assignment 4
 * Etienne Berube: 40052212
 * Braldey Walsh: 40063018
 */
#ifndef ASSINGMENT_4_EDGE_H
#define ASSINGMENT_4_EDGE_H

#include <ostream>
#include "Node.h"

class Edge
{
	public:
		Edge() = default; //does nothing
        Edge(const Edge& edge);
		Edge(Node *n1, Node* n2);
        Edge(int id1, int id2, int weight);
		~Edge() = default;
		void setWeight(int _weight) { weight = _weight; }
		int getWeight() const { return weight; }
        void incrementWeight(){weight++;}
		void setStartNode(int _startNode){ startNode = _startNode; }
		void setEndNode(int _endNode){ endNode = _endNode; }
		int getStartNode() const { return startNode; }
		int getEndNode() const { return endNode; }

    bool operator==(const Edge &rhs) const;

    bool operator!=(const Edge &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Edge &edge);


protected:
		int startNode, endNode; //integer ID values of start and end nodes
		int weight;//weight of the edge
};


#endif //ASSINGMENT_4_EDGE_H
