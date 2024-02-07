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

    void removeVertex(int vertex) {
        Node* current = graph[source].head;
        graph[vertex] = nullptr;

        for (int i = 0; i < v; i++) {
            Node* current = graph[i];
            Node* previous = nullptr;

            while (current != nullptr) {
                if (current->vertex == vertex) {
                    if (previous == nullptr) {
                        graph[i] = current->next;
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
    }

    void bfs() {
        bool* visited = new bool[v];
        for (int i = 0; i < v; i++) {
            visited[i] = false;
        }

        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int vertex = q.front();
                    q.pop();
                    cout << vertex << " ";

                    Node* temp = graph[vertex];
                    while (temp != nullptr) {
                        if (!visited[temp->vertex]) {
                            q.push(temp->vertex);
                            visited[temp->vertex] = true;
                        }
                        temp = temp->next;
                    }
                }
            }
        }

        delete[] visited;
    }

    void DFS(int** edges, int v, bool* visited, int si) {
        visited[si] = true;
        cout << si << " ";
        for (int i = 0; i < v; i++) {
            if (i == si) {
                continue;
            }
            if (!visited[i] && edges[si][i] == 1) {
                DFS(edges, v, visited, i);
            }
        }
    }

    void PrintGraph() {
        for (int i = 0; i < v; ++i) {
            cout << i << " ";
            Node* temp = graph[i];
            while (temp != nullptr) {
                cout << "-> " << temp->vertex << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

};