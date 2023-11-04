#include <iostream>
#include <queue>
#include <bits/stdc++.h>
#include <limits>
#include <algorithm>
#include <time.h>
#include <chrono>
#include "shortest_path.h"


using namespace std;
using namespace std::chrono;


        int Directed_Graph::get_index_from_adjlist(int u){
            for (int i = 0; i < head; i++){
                if (adjList[i]->data == u){
                    return i;
                }
            }
            return -1;

        }

        bool Directed_Graph::isEmpty(){
            if (head == 0){
                return 1;

            }
        return 0;
        }


         void Directed_Graph::addEdge(int u, int v, int weight){
            Vertex *newNode = new Vertex;
            newNode-> data = v;
            int i = get_index_from_adjlist(u);
            int j = get_index_from_adjlist(v);
            adjMatrix[i][j] = weight;
            }

        void Directed_Graph::addVertex(int data){
            if (head > numVertices){
                cout << "Graph is full\n";
                return;
            }
            Vertex *newNode = new Vertex;
            newNode->data = data;
            newNode->next = nullptr;
            newNode->pred = nullptr;

            adjList[head] = newNode;
            head++;

        }


        void Directed_Graph::deleteVertex(int data) {
            int j = get_index_from_adjlist(data);
            if (j == -1) {
                cout << "Vertex not found\n";
                return;
            }

            for (int i = 0; i < head; i++) {
                if (i == j) {
                    Vertex* curr = adjList[i];
                    while (curr != nullptr) {
                        Vertex* temp = curr;
                        curr = curr->next;
                        delete temp;
                    }
                    adjList[i] = nullptr;
                    for (int k = 0; k < head - j; k++) {
                        adjList[j + k] = adjList[j + k + 1];
                    }
                    adjList[head] = nullptr;
                    head--;
                    continue;
                }
            }
            int **temp;;
            temp = new int*[head];
            for (int i = 0; i < head; i++){
                temp[i] = new int [head];
                }
            int x = 0;
            for (int i = 0; i < head+1; i++){
                int y = 0;
                for (int k = 0; k < head+1; k++){
                    if ((i == j) || (k==j)){
                        continue;
                    }
                    else{
                        temp[x][y] = adjMatrix[i][k];
                        y++;
                    };
                }
                if (i != j){
                    x++;
                }
            }

            adjMatrix = temp;

        }

        void Directed_Graph::deleteEdge(int u, int v){
            int m = get_index_from_adjlist(u);
            int n = get_index_from_adjlist(v);
            if (m == -1 || n == -1){
                cout << "Vertex not found\n";
                return;
            }

            adjMatrix[m][n] = std::numeric_limits<int>::max();

        }

         void Directed_Graph::printGraph() {
            for (int i = 0; i < head; ++i){
                cout << adjList[i]->data << ": ";
                for (int j=0; j<head; j++){
                    if (adjMatrix[i][j] == std::numeric_limits<int>::max()){
                        cout << "INF ";
                        continue;
                    }
                    cout << adjMatrix[i][j] << " ";
                }
                cout << endl;
            }
            }


        void Directed_Graph::initialize_single_source(int data){
            int s = get_index_from_adjlist(data);

            for (int i = 0; i < head; ++i) {
                Vertex* curr = adjList[i];
                curr->d = (i == s) ? 0 : std::numeric_limits<int>::max();
                curr->pred = nullptr;
            }

        }

        int Directed_Graph::weight(int u, int v){
            return adjMatrix[get_index_from_adjlist(u)][get_index_from_adjlist(v)];
        }

        void Directed_Graph::relax(int u, int v){
            int i = get_index_from_adjlist(u);
            int j = get_index_from_adjlist(v);
                if ((adjList[j]->d)  > (adjList[i]->d + weight(u,v)) && adjList[i]->d != std::numeric_limits<int>::max()){
                    adjList[j]->d = adjList[i]->d + weight(u,v);
                    adjList[j]->pred = adjList[u];

            }


        }

        int Directed_Graph::get_num_edges(){
            int n = 0;
            for (int i = 0; i < head; i++){
                for (int j = 0; j < head; j++){
                    if (adjMatrix[i][j] == 0 || adjMatrix[i][j] == std::numeric_limits<int>::max()){
                        continue;
                    }
                    n++;
                }
            }
            return n;
        }

        bool Directed_Graph::Bellman_Ford_algo(int s) {
            initialize_single_source(s);

            for (int i = 0; i < head - 1; i++) {
                for (int j = 0; j < head; j++) {
                    for (int k = 0; k < head; k++) {
                        if (adjMatrix[j][k] == 0 || adjMatrix[j][k] == std::numeric_limits<int>::max()) {
                            continue;
                        }
                        int u = adjList[j]->data;
                        int v = adjList[k]->data;
                        relax(u, v);

                    }
                }
            }



            for (int i = 0; i < head; i++) {
                for (int j = 0; j < head; j++) {
                    if (adjMatrix[i][j] == std::numeric_limits<int>::max()) {
                        continue;
                    }
                    if (adjList[j]->d > adjList[i]->d + weight(adjList[i]->data, adjList[j]->data)) {
                        return false;
                    }
                }
            }

            return true; // No negative weight cycles found
        }


        void Directed_Graph::Bellman_Ford(int s){
            if (isEmpty()){
                cout << "Graph is empty\n";
                return;
            }

            bool t = Bellman_Ford_algo(s);
            if (t){
                for (int i = 0; i < head; i++){
                    cout <<adjList[i]->d<<endl;
                }
            }
            else{
                cout << "There are negative weight cycles in this graph\n";
            }
        }




        bool Directed_Graph::check_negative_weights(){
            for (int i = 0; i < head; i++){
                for (int j = 0; j < head; j++){
                    if (adjMatrix[i][j] < 0){
                        return 1;
                    }
                }
            }
            return 0;
        }

        Vertex **Directed_Graph::Dijkstra_algo(int s){
            if (check_negative_weights()){
                cout << "This algorithm can't work with this graph since it has negative weights"<<endl;
                return nullptr;
            }
            Vertex **result = adjList;
            priority_queue<iPair, vector<iPair>, greater<iPair> > Q;
            initialize_single_source(s);
            int i = get_index_from_adjlist(s);

            Q.push(make_pair(result[i]->d, result[i]->data));

            while (!Q.empty()) {
                    int u = Q.top().second;
                    Q.pop();

                    int x = get_index_from_adjlist(u);

                    for (int j = 0; j < head; j++) {
                        if (adjMatrix[x][j] == std::numeric_limits<int>::max()) {
                            continue;
                        } else {
                            int weight = adjMatrix[x][j];

                            if (result[j]->d > result[x]->d + weight) {
                                result[j]->d = result[x]->d + weight;
                                Q.push(make_pair(result[j]->d, result[j]->data));
                            }
                        }
                    }
                }

            return result;

        }

        void Directed_Graph::Dijkstra(int s){
            if (isEmpty()){
                cout << "Graph is empty\n";
                return;
            }
            Vertex **result = Dijkstra_algo(s);
            for (int i = 0; i < head; i++) {
                cout << result[i]->data << " : " << result[i]->d << endl;
                }
        }

        int **Directed_Graph::Floyd_Warshall_algo(){
            int **A = adjMatrix;
            for (int k = 0; k < head; k++){
                for (int i = 0; i < head; i++){
                    for (int j = 0; j < head; j++){
                        if (A[i][k] != std::numeric_limits<int>::max() && A[k][j] != std::numeric_limits<int>::max()){
                            A[i][j] = std::min(A[i][j], A[i][k] + A[k][j]);
                        }
                    }
                }
            }

            return A;

        }

        void Directed_Graph::Floyd_Warshall(){
            if (isEmpty()){
                cout << "Graph is empty\n";
                return;
            }
            int **A = Floyd_Warshall_algo();
             for (int i = 0; i < head; ++i){
                cout << adjList[i]->data << ": ";
                for (int j=0; j<head; j++){
                    if (A[i][j] == std::numeric_limits<int>::max()){
                        cout << "INF ";
                        continue;
                    }
                    cout << A[i][j] << " ";
                }
                cout << endl;
            }
        }

        void Directed_Graph::compare_performance(){
            if (isEmpty()){
                cout << "Graph is empty\n";
                return;
            }
            cout << "Performance of Dijkstra Algorithm: \n";
            srand(time(NULL));

            auto start1 = high_resolution_clock::now();

            Dijkstra_algo(0);

            auto stop1 = high_resolution_clock::now();
            auto duration1 = duration_cast<nanoseconds>(stop1-start1);

            cout << "Time taken by Dijkstra Algorthim to find single source shortest path  is given by " << duration1.count() << " seconds "<< "\n";
            cout << "\n";

            cout << "Performance of Bellman-Ford Algorithm: \n";
            srand(time(NULL));

            auto start2 = high_resolution_clock::now();

            Bellman_Ford_algo(0);

            auto stop2 = high_resolution_clock::now();
            auto duration2 = duration_cast<nanoseconds>(stop2-start2);

            cout << "Time taken by Bellman-Ford Algorthim to find single source shortest path  is given by " << duration2.count() << " seconds "<< "\n";
            cout << "\n";

            cout << "Performance of Floyd_Warshall Algorithm: \n";
            srand(time(NULL));

            auto start3 = high_resolution_clock::now();

            Floyd_Warshall_algo();

            auto stop3 = high_resolution_clock::now();
            auto duration3 = duration_cast<nanoseconds>(stop3-start3);

            cout << "Time taken by Floyd_Warshall Algorthim to find all source shortest path  is given by " << duration3.count() << " seconds "<< "\n";
            cout << "\n";
        }

        void Directed_Graph::compare_performance_predefined(){
			Directed_Graph graph(10);
            addVertex(0);
            addVertex(1);
            addVertex(2);
            addVertex(3);
            addVertex(4);

            addEdge(0, 1, 10);
            addEdge(0, 3, 5);
            addEdge(1, 3, 2);
            addEdge(1, 2, 1);
            addEdge(1, 4, 7);
            addEdge(2, 4, 4);
            addEdge(3, 1, 3);
            addEdge(3,2, 9);
            addEdge(3,4, 2);
            addEdge(4, 2, 6);
            addEdge(4, 0, 7);

			if (isEmpty()){
                cout << "Graph is empty\n";
                return;
            }
            cout << "Performance of Dijkstra Algorithm: \n";
            srand(time(NULL));

            auto start1 = high_resolution_clock::now();

            Dijkstra_algo(0);

            auto stop1 = high_resolution_clock::now();
            auto duration1 = duration_cast<nanoseconds>(stop1-start1);

            cout << "Time taken by Dijkstra Algorthim to find single source shortest path  is given by " << duration1.count() << " seconds "<< "\n";
            cout << "\n";

            cout << "Performance of Bellman-Ford Algorithm: \n";
            srand(time(NULL));

            auto start2 = high_resolution_clock::now();

            Bellman_Ford_algo(0);

            auto stop2 = high_resolution_clock::now();
            auto duration2 = duration_cast<nanoseconds>(stop2-start2);

            cout << "Time taken by Bellman-Ford Algorthim to find single source shortest path  is given by " << duration2.count() << " seconds "<< "\n";
            cout << "\n";

            cout << "Performance of Floyd_Warshall Algorithm: \n";
            srand(time(NULL));

            auto start3 = high_resolution_clock::now();

            Floyd_Warshall_algo();

            auto stop3 = high_resolution_clock::now();
            auto duration3 = duration_cast<nanoseconds>(stop3-start3);

            cout << "Time taken by Floyd_Warshall Algorthim to find all source shortest path  is given by " << duration3.count() << " seconds "<< "\n";
            cout << "\n";


			deleteVertex(0);
			deleteVertex(1);
			deleteVertex(2);
			deleteVertex(3);
			deleteVertex(4);

		}


        void Directed_Graph::example_Dijkstra(){
            Directed_Graph graph(10);
            graph.addVertex(0);
            graph.addVertex(1);
            graph.addVertex(2);
            graph.addVertex(3);
            graph.addVertex(4);

            graph.addEdge(0, 1, 10);
            graph.addEdge(0, 3, 5);
            graph.addEdge(1, 3, 2);
            graph.addEdge(1, 2, 1);
            graph.addEdge(1, 4, 7);
            graph.addEdge(2, 4, 4);
            graph.addEdge(3, 1, 3);
            graph.addEdge(3,2, 9);
            graph.addEdge(3,4, 2);
            graph.addEdge(4, 2, 6);
            graph.addEdge(4, 0, 7);

            graph.printGraph();
            cout <<endl;
            graph.Dijkstra(0);
        }

        void Directed_Graph::example_Bellman(){
            Directed_Graph graph(10);
            graph.addVertex(0);
            graph.addVertex(1);
            graph.addVertex(2);
            graph.addVertex(3);
            graph.addVertex(4);

            graph.addEdge(0, 1, 6);
            graph.addEdge(0, 3, 7);
            graph.addEdge(1, 3, 8);
            graph.addEdge(1, 2, 5);
            graph.addEdge(1, 4, -4);
            graph.addEdge(2, 1, -2);
            graph.addEdge(3, 2, -3);
            graph.addEdge(3, 4, 9);
            graph.addEdge(4, 2, 7);
            graph.addEdge(4, 0, 2);

            graph.printGraph();
            cout <<endl;
            graph.Bellman_Ford(0);

;        }

        void Directed_Graph::example_Floyd(){
            Directed_Graph graph(10);
            graph.addVertex(0);
            graph.addVertex(1);
            graph.addVertex(2);
            graph.addVertex(3);
            graph.addVertex(4);

            graph.addEdge(0, 1, 3);
            graph.addEdge(0, 2, 8);
            graph.addEdge(0, 4, -4);
            graph.addEdge(1, 3, 1);
            graph.addEdge(1, 4, 7);
            graph.addEdge(2, 1, 4);
            graph.addEdge(3, 0, 2);
            graph.addEdge(3,2, -5);
            graph.addEdge(4, 3, 6);
            graph.printGraph();
            cout <<endl;
            graph.Floyd_Warshall();

        }

