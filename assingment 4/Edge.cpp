//
// Created by Etienne on 17/03/2018.
//

#include "Edge.h"

Edge::Edge(Node *n1, Node *n2)
{
	setStartNode(n1->getId());
	setEndNode(n2->getId());
}



