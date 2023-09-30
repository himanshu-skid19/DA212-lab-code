#include <iostream>
using namespace std;

struct Vertex {
    int data;
    Vertex* next;
};

class Graph {
    private:
        int numVertices;
        Vertex **adjList;

public:
    Graph(int numVertices){
        this->numVertices = numVertices;
        adjList = new Vertex *[numVertices];
        for (int i = 0; i < numVertices; i++){
            adjList[i] = nullptr;
        }
    }

    void addEdge(int u, int v){
        Vertex *newNode = new Vertex;
        newNode-> data = v;
        newNode->next = adjList[u];
        adjList[u] = newNode;

        // being an undirected graph, must add an edge in the opposite direction as well

        newNode = new Vertex;
        newNode->data = u;
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }

    void addVertex(int data){
        Vertex *newNode = new Vertex;
        newNode->data = data;
        newNode->next = nullptr;

        adjList[data] = newNode;
    }

    void printGraph() {
        for (int i = 0; i < numVertices; ++i){
            Vertex *curr = adjList[i];
            cout << "Vertex " << i << " connected to: ";
            while (curr){
                cout << curr->data << " ";
                curr = curr->next;

            }
            cout << "\n";
        }
    }

};

int main(void){
    Graph graph(5);

    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.printGraph();
}


