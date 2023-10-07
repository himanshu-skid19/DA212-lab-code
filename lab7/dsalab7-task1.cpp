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


    void test(){
        cout << adjList[0]->data << "\n";
        int x = get_index_from_adjlist(4);
        cout << x << "\n";
    }
};

int main(void){
    cout << "Welcome to this program, how many vertices do you want your graph to have? \n";
    int num;
    cin >> num;
    Graph graph(num);

    int input;
	while (input != 6){
		cout << "Enter 1 to add a vertex to the graph\n";
		cout << "Enter 2 to add an edge between two vertices\n";
		cout << "Enter 3 to delete a vertex from the graph\n";
		cout << "Enter 4 to delete a edge between two vertices\n";
		cout << "Enter 5 to print the adjacency list representing the graph\n";
		cout << "Enter 6 to exit the program\n";
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
		}
	}


}
