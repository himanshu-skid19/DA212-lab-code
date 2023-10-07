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
        int head;

public:
    Graph(int numVertices){
        this->numVertices = numVertices;
        adjList = new Vertex *[numVertices];
        for (int i = 0; i < numVertices; i++){
            adjList[i] = nullptr;
        }
        head = 0;
    }

    int get_index_from_adjlist(int u){
        for (int i = 0; i < head; i++){
            if (adjList[i]->data == u){
                return i;
            }
        }
        return -1;

    }

    void addEdge(int u, int v){
        Vertex *newNode = new Vertex;
        newNode-> data = v;
        int i = get_index_from_adjlist(u);
        Vertex *curr = adjList[i];
        while (curr->next != NULL){
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->next = NULL;


        // being an undirected graph, must add an edge in the opposite direction as well

        newNode = new Vertex;
        newNode->data = u;
        int j = get_index_from_adjlist(v);
        curr = adjList[j];
        while (curr->next != NULL){
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->next = NULL;
    }

    void addVertex(int data){
        if (head > numVertices){
            cout << "Graph is full\n";
            return;
        }
        Vertex *newNode = new Vertex;
        newNode->data = data;
        newNode->next = nullptr;

        adjList[head] = newNode;
        head++;
    }
    
   void deleteVertex(int data){
        int j = get_index_from_adjlist(data);
        if (j == -1){
            cout << "Vertex not found";
            return;
        }

        for (int i = 0; i < head; i++){
            cout << j << "\n";
            if (i == j){
                Vertex *curr = adjList[i];
                while (curr != nullptr){
                    Vertex* temp =curr;
                    curr=curr->next;
                    delete temp;
                }
                adjList[i] = nullptr;
                for (int k = 0; k < head - j; k++){
                    adjList[j+k] = adjList[j+k+1];
                }
                adjList[head] = nullptr;
                head--;
                continue;
            }
            else{
                Vertex *curr = adjList[i];
                Vertex *prev = curr;
                curr = curr->next;
                while (curr != nullptr){
                    if (curr -> data == data){

                        prev->next = curr->next;
                        delete curr;
                        break;
                    }
                    else{
                        prev = curr;
                        curr = curr->next;
                    }
                }
            }
        }
   }

    void printGraph() {
        for (int i = 0; i < head; ++i){
            Vertex *curr = adjList[i];
            cout << i << ": ";
            while (curr){
                cout << curr->data << " ";
                curr = curr->next;

            }
            cout << "\n";
        }
    }


    void test(){
        cout << adjList[0]->data << "\n";
        int x = get_index_from_adjlist(4);
        cout << x << "\n";
    }
};

int main(void){
    Graph graph(5);

    graph.addVertex(4);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(1);
    graph.addVertex(0);

    graph.addEdge(4,2);
    graph.addEdge(4,3);
    graph.addEdge(2,1);
    graph.addEdge(3,0);

    graph.printGraph();
    graph.deleteVertex(2);
    cout << "\n";
    graph.printGraph();
    // graph.printGraph();
}
