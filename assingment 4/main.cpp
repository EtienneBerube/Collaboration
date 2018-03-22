#include <iostream>
#include "Adirectional_Graph.h"
#include "Node.h"
#include "Edge.h"

int main() {
    ADirectional_Graph g1;

    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    Node n6(6);
    Node n7(7);

    g1.addNode(n1);
    g1.addNode(n2);
    g1.addNode(n3);
    g1.addNode(n4);
    g1.addNode(n5);
    g1.addNode(n6);
    g1.addNode(n7);

    Edge e1(&n1,&n2);
    Edge e2(&n3,&n1);
    //Edge e3(&n2,&n4);
    Edge e4(&n3,&n4);
    Edge e5(&n2,&n3);

    g1.addEdge(e1);
    g1.addEdge(e2);
    //g1.addEdge(e3);
    g1.addEdge(e4);
    g1.addEdge(e5);

    g1.printGraphNodes();
    g1.printGraphEdges();

    g1.printDegreesDebug();

    g1.display(n4);
    std::cout<<std::endl;
    g1.display(e4);

	return 0;
}