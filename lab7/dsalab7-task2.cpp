#include <iostream>
#include <string.h>
using namespace std;

struct Vertex {
    int data;
    Vertex* next;
    string color;
    long long d;
    Vertex *parent;
};

class Node {
	public:
		Node *next;
		int data;

		Node(){
			data = NULL;
			next = NULL;

		}

		Node(int data) {
		this->data = data;
		this->next = NULL;
		}
};

class queue {
	Node *head;
	Node *tail;
	public:
		queue() {head = NULL; tail == NULL;}

		int IsEmpty(){
			if (head == NULL){
				return 0;
			}
			return 1;
		}

		void enqueue(int data){
			Node *new_node = new Node(data);
			if (head == NULL){
				head = new_node;
				return;
			}
			Node *temp = head;
			while (temp->next != NULL){
				temp = temp->next;
			}
			temp->next = new_node;
			tail = new_node;
			return;

		}

		void printqueue() {
			Node *curr = head;

			if (head == NULL) {
				cout << "queue is empty\n";
				return;
			}
			while (curr != NULL) {
				cout << curr->data << " ";
				curr = curr->next;
			}
			cout << "\n";
		}

		int dequeue(){
			if (head == NULL) {cout << "The queue is empty\n"; return -1;}
			Node *temp = head;
			head = head->next;
			return temp->data;
		}

		int front(){
			if (head == NULL){
				printf("Queue is empty\n");
				return 0;
			}
			return head->data;
		}
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
            cout << "Vertex not found\n";
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

    void deleteEdge(int u, int v){
        int m = get_index_from_adjlist(u);
        int n = get_index_from_adjlist(v);
        if (m == -1 || n == -1){
            cout << "Vertex not found\n";
            return;
        }

        Vertex *curr = adjList[m];
        Vertex *prev = curr;
        curr = curr->next;
        while (curr != nullptr){
            if (curr -> data == v){
                prev->next = curr->next;
                delete curr;
                break;
            }
            else{
                prev = curr;
                curr = curr->next;
            }

    }
        curr = adjList[n];
        prev = curr;
        curr = curr->next;
            while (curr != nullptr){
            if (curr -> data == u){
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


    void BFS(int data){
        Graph g2(numVertices);

        int i = get_index_from_adjlist(data);
        for (int j = 0; j < head; j++){
            Vertex *curr = adjList[j];
            while (curr != nullptr){
            curr->color = "WHITE";
            curr->d = 1e18;
            curr->parent = NULL;
            curr=curr->next;

            }
        }
        adjList[i]->color = "GRAY";
        adjList[i]->d = 0;
        adjList[i]->parent = NULL;

        queue q;
        q.enqueue(adjList[i]->data);
        while (q.IsEmpty() != 0){
            int u = q.dequeue();
            int idx = get_index_from_adjlist(u);
            Vertex *curr = adjList[idx];
            while (curr != nullptr){
                if (curr->color == "WHITE" && curr->color != "BLACK"){

                    int x = get_index_from_adjlist(curr->data);
                    for (int z = 0; z<numVertices; z++){
                        Vertex *temp = adjList[z];
                        while (temp != nullptr){
                            if (temp->data == curr->data){
                                temp->color = "GRAY";
                                temp->d = adjList[idx]->d + 1;
                                temp->parent = adjList[idx];

                            }
                            temp = temp->next;
                        }
                    };
                    q.enqueue(curr->data);
                }

                curr = curr->next;
            }

            for (int z = 0; z<head; z++){
                Vertex *temp = adjList[z];
                while (temp != nullptr){
                    if (temp->data == u){
                        temp->color = "BLACK";

                    }
                    temp = temp->next;
                }
            }
        }

        cout << "Vertex : Minimum Distance\n";
        for (int i = 0; i < head; i++){
            cout << adjList[i] -> data << " : " <<  adjList[i]->d << endl;
        }
    }

};

int main(void){
    Graph graph(10);
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);
    graph.addVertex(5);
    graph.addVertex(6);
    graph.addVertex(7);
    graph.addVertex(8);
    graph.addVertex(9);

    graph.addEdge(1,2);
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    graph.addEdge(2,9);
    graph.addEdge(3,4);
    graph.addEdge(3,6);
    graph.addEdge(4,5);
    graph.addEdge(4,9);
    graph.addEdge(5,6);
    graph.addEdge(5,8);
    graph.addEdge(6,7);
    graph.addEdge(7,8);
    graph.addEdge(8,9);

    graph.printGraph();

    graph.BFS(5);











}
