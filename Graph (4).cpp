#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int vertex;
    Node* next;
};

class Graph {
private:
    int v;
    Node** graph;

public:
    Graph(int vertices) {
        v = vertices;
        graph = new Node * [v];
        for (int i = 0; i < v; i++) {
            graph[i] = nullptr;
        }
    }

    void addEdge(int source, int destination) {
        Node* node = new Node();
        node->vertex = destination;
        node->next = graph[source];
        graph[source] = node;
    }

    void addVertex(int vertex) {
        if (vertex >= 0 && vertex < v && graph[vertex] == nullptr) {
            graph[vertex] = new Node();
            graph[vertex]->vertex = vertex;
            graph[vertex]->next = nullptr;
        }
    }

    void removeEdge(int source, int destination) {
        Node* current = graph[source];
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->vertex == destination) {
                if (previous == nullptr) {
                    graph[source] = current->next;
                }
                else {
                    previous->next = current->next;
                }
                delete current;
                break;
            }

            previous = current;
            current = current->next;
        }
    }