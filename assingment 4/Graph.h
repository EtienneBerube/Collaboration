//
// Created by Etienne on 17/03/2018.
//

#ifndef ASSINGMENT_4_GRAPH_H
#define ASSINGMENT_4_GRAPH_H

class Node;
class Edge;

#include <iostream>
#include <vector>

class Graph{
protected:
    std::vector<Node*> nodes;
    std::vector<Edge*> edges;
public:
    Graph();

    virtual ~Graph();
//adds one vertex; returns bool if added successfully.
    virtual bool addNode(Node& v)=0;
//Bonus question: adds in a set of vertices; returns bool if added
    //successfully
//virtual bool addVertices(Node* vArray) = 0;
//removes a vertex; the edges that have connection with this vertex need to
    //be removed;
    virtual bool removeNode(Node& v) = 0;
//adds an edge; returns true if the edge is added successfully.
    virtual bool addEdge(Edge& e) = 0;
//Bonus question: removes a set of edges; as a result, some nodes may remain
    //as orphan.
// removeEdge the edge
    virtual bool removeEdge(Edge &e) = 0;

    virtual bool removeMultipleEdges(Edge *e, int length) = 0;
// returns bool if a vertex exists in a graph.
    virtual bool searchNode(const Node& v) = 0;
// returns bool if an Node exists in a graph.
    virtual bool searchEdge(const Edge& e) = 0;
// displays the path that contains the vertex.
    virtual void display(Edge& v) const = 0;
// displays the path that contains the edge.
    virtual void display(Node& e) const = 0;
// displays the whole graph with your own defined format
    virtual void display() const = 0;
    // converts the whole graph to a string such as 1-2-4-5; 1-3-5; each path
    // is separated by ';'
    virtual std::string toString () = 0;
//removeEdge all the vertices and edges;
    virtual bool clean() = 0;

    Graph& operator++();

    Graph& operator=(const Graph &rhs);

    bool operator<(const Graph &rhs) const;

    bool operator>(const Graph &rhs) const;

    bool operator==(const Graph &rhs) const;

    bool operator!=(const Graph &rhs) const;

    std::vector<Edge *> &getEdges() const;

    std::vector<Node *> &getNode() const;
};



#endif //ASSINGMENT_4_GRAPH_H
