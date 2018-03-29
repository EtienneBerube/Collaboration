/*
 * COEN 244 Assignment 4
 * Etienne Berube: 40052212
 * Braldey Walsh: 40063018
 */

#include "Acyclic_Graph.h"
#include "Node.h"
#include "Edge.h"

int main() {
	//create the graphs
    Acyclic_Graph g1;
    Acyclic_Graph g2;
    Acyclic_Graph g3;
    Acyclic_Graph g4;

	//create notes
    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    Node n6(6);
    Node n7(7);

	//add nodes to g1
    g1.addNode(n1);
    g1.addNode(n2);
    g1.addNode(n3);
    g1.addNode(n4);
    g1.addNode(n5);
    g1.addNode(n6);
    g1.addNode(n7);

	//create edges
    Edge e1(&n1,&n2);
    Edge e2(&n1,&n3);
    Edge e3(&n2,&n4);
    Edge e4(&n3,&n4);
    Edge e5(&n2,&n3);
	
	//add edges to g1
    g1.addEdge(e1);
    g1.addEdge(e2);
    g1.addEdge(e3);
    g1.addEdge(e4);
    g1.addEdge(e5);

	//print graphs
    g1.printGraphNodes();
    g1.printGraphEdges();

	//display g1 with nodes and edges
    g1.display(n4);
    std::cout<<std::endl;
    g1.display(e4);
    std::cout<<"\nRepresentation of this graph:\n"<<g1<<std::endl;

	//test operators
    g2 = g1;
    std::cout<<"Equal?(g1 vs g2): "<< (g1==g2) <<std::endl;
    ++g2;
    std::cout<<"Is g2 greater (after incrementing the weights?: )"<< (g2 > g1) << std::endl;

    std::cout<<"Adding g1 and g4"<<std::endl;
    Node n8(8);
    Node n9(9);
    Node n10(10);

    g4.addNode(n8);
    g4.addNode(n9);
    g4.addNode(n10);

    g3 = g1+g4;
    g3.printGraphNodes();
    g3.printGraphEdges();
	
	//test adjacency matrix
	cout << endl << "Print adjacency matrix:" <<  endl;
	g1.display();

	g1.removeEdge(e1); //remove e1
	g1.removeNode(n7); //remove n7
	cout << endl << endl << "Print matrix again after removing a node and an edge:" << endl;
	g1.display();

	g1.removeMultipleEdges(&e3, 2); //remove e3 and the following edge
	cout << endl << endl << "Final print of matrix after having removed another node calling the 'removeMultipleEdges' function:" << endl;
	g1.display();

	return 0;
}