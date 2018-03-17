//
// Created by Etienne on 17/03/2018.
//

#ifndef ASSINGMENT_4_EDGE_H
#define ASSINGMENT_4_EDGE_H

#include "Node.h"

class Edge
{
	public:
		Edge() {}; //does nothing
		Edge(Node & n1, Node n2);
		~Edge() {};
		void setWeight(int _weight) { weight = _weight; }
		int getWeight() const { return weight; }
		void setStartNode(int _startNode) { startNode = _startNode; }
		void setEndNode(int _endNode) { endNode = _endNode; }
		int getStartNode() const { return startNode; }
		int getEndNode() const { return endNode; }

	protected:
		int startNode, endNode; //integer ID values of start and end nodes
		int weight;//weight of the edge
};


#endif //ASSINGMENT_4_EDGE_H
