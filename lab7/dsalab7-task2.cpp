#include <iostream>
#include <string.h>
using namespace std;

struct Vertex {
    int data;
    Vertex* next;
    string color;
    long long d;
    long long f;
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
        long long t;
        int num_edges;

public:
    Graph(int numVertices){
        this->numVertices = numVertices;
        adjList = new Vertex *[numVertices];
        for (int i = 0; i < numVertices; i++){
            adjList[i] = nullptr;
        }
        head = 0;
        this->t = 0;
        this->num_edges=0;
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

        num_edges++;
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
                    for (int z = 0; z<head; z++){
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

    int isEdge(int u, int v){
        int idx = get_index_from_adjlist(u);
        Vertex *curr = adjList[idx];
        while (curr != nullptr){
            if (curr->data == v){
                return 0;
            }
            curr= curr->next;
        }

        return 1;
    }

    void DFS(){
        for (int j = 0; j < head; j++){
            Vertex *curr = adjList[j];
            while (curr != nullptr){
            curr->color = "WHITE";
            curr->d = 1e18;
            curr->parent = NULL;
            curr=curr->next;

            }
        }
        string col = adjList[0]->color;
        DFS_RUN(0, col);

        cout << "Vertex : timestamp for first visit | timestamp for final visit\n";
        for (int i = 0; i < head; i++){
            cout << adjList[i] -> data << " : " <<  adjList[i]->d << " | " << adjList[i]->f << endl;
        }

    }

    void DFS_RUN(int u, string col){
        t++;
        adjList[u]->color = "GRAY";
        adjList[u]->d = t;

        for (int i = 0; i < head; i++){
            if (isEdge(adjList[u]->data, adjList[i]->data) ==0  && adjList[i]->color == "WHITE"){
                DFS_RUN(i, "WHITE");
            }

        }
        t++;
        adjList[u]->color = "BLACK";
        adjList[u]->f = t;


    }

    int get_num_edges(){
        return num_edges;
    }

    void find_tree(){
        int count = 0;
        for (int i = 0; i < head; i++){
            if (adjList[i]->next == NULL){
                count++;
            }
        }
        cout << head <<endl;

        if (count != 0 && (get_num_edges() != head-1)){
            cout << "Graph is not a tree\n";
            return;
        }
        cout << "Graph is a tree\n";
        return;
    }
};

int main(void){
    cout << "Welcome to this program, how many vertices do you want your graph to have? \n";
    int num;
    cin >> num;
    Graph graph(num);

    int input;
	while (input != 10){
		cout << "Enter 1 to add a vertex to the graph\n";
		cout << "Enter 2 to add an edge between two vertices\n";
		cout << "Enter 3 to delete a vertex from the graph\n";
		cout << "Enter 4 to delete a edge between two vertices\n";
		cout << "Enter 5 to print the adjacency list representing the graph\n";
        cout << "Enter 6 to get the number of edges in the graph\n";
        cout << "Enter 7 to perform Breadth First Search (BFS) onthe graph\n";
        cout << "Enter 8 to perform Depth First Search on the graph\n";
        cout << "Enter 9 to check if the graph is a tree\n";
		cout << "Enter 10 to exit the program\n";
		cout << "What do you want to do? \n";
		cin >> input;
		switch (input){
			case 1:
				int val;
				cout << "Enter the value of the vertex: \n";
				cin >> val;
				graph.addVertex(val);
				break;
			case 2:
				int m;
                int n;
                cout << "Enter the value of the first vertex: \n";
				cin >> m;
                cout << "Enter the value of the second vertex: \n";
				cin >> n;
				graph.addEdge(m, n);
				break;
			case 3:
				int key;
				cout << "Enter the value of the vertex you want to delete: \n";
				cin >> key;;
				graph.deleteVertex(key);
				break;
			case 4:
				int x;
                int y;
                cout << "Enter the value of the first vertex: \n";
				cin >> x;
                cout << "Enter the value of the second vertex: \n";
				cin >> y;
				graph.deleteEdge(x, y);
				break;
			case 5:
				graph.printGraph();
				break;
            case 6:
				cout << graph.get_num_edges() <<endl;
				break;

            case 7:
                int d;
                cout << "Enter the element for which you want to perform the BFS: ";
                cin >> d;
				graph.BFS(d);
				break;

            case 8:
				graph.DFS();
				break;
            case 9:
				graph.find_tree();
				break;
		}
	}

}
