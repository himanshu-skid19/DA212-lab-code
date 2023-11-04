#include <iostream>
#include "shortest_path.h"

#include <stack>

using namespace std;


void run(){

    cout << "Welcome to this program that demostrates various graph algorithms, how many nodes do you want in your graph? \n";
    int num;
    cin >> num;
    Directed_Graph graph(num);

    int input;
	while (input != 15){
		cout << "Enter 1 to add a vertex to the graph\n";
		cout << "Enter 2 to add an edge between two vertices\n";
		cout << "Enter 3 to delete a vertex from the graph\n";
		cout << "Enter 4 to delete a edge between two vertices\n";
		cout << "Enter 5 to print the adjacency matrix representing the graph\n";
        cout << "Enter 6 to get the number of edges in the graph\n";
        cout << "Enter 7 to run Dijkstra's algorithm'\n";
        cout << "Enter 8 to run Bellman-Ford algorithm\n";
        cout << "Enter 9 to run Floyd-Warshall algorithm\n";
		cout << "Enter 10 to run a predefined example for Dijkstra algorithm\n";
        cout << "Enter 11 to run a predefined example for Bellman-Ford algorithm\n";
        cout << "Enter 12 to run a predefined example for Floyd-Warshall\n";
        cout << "Enter 13 to compare between the various algorithms\n";
        cout << "Enter 14 to compare between the various algorithms on predefined example\n";
        cout << "Enter 15 to exit\n";



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
                int w;
                cout << "Enter the value of the first vertex: \n";
				cin >> m;
                cout << "Enter the value of the second vertex: \n";
				cin >> n;
                cout << "Enter the weight of the edge: \n";
				cin >> w;
				graph.addEdge(m, n, w);
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
                cout << "Enter the source: ";
                cin >> d;
				graph.Dijkstra(d);
				break;

            case 8:
				int s;
                cout << "Enter the source: ";
                cin >> s;
				graph.Bellman_Ford(d);
				break;
            case 9:
				graph.Floyd_Warshall();
				break;
            case 10:
				graph.example_Dijkstra();
				break;
            case 11:
				graph.example_Bellman();
				break;
            case 12:
				graph.example_Floyd();
				break;
            case 13:
				graph.compare_performance();
				break;
            case 14:
				graph.compare_performance_predefined();
				break;


		}

    }


}
