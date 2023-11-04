#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H
#include <string>
#include <limits>

using namespace std;


struct Vertex {
    int data;
    int d;
    Vertex *pred;
    Vertex *next;
};

typedef pair<int, int> iPair;

class Directed_Graph{
    private:
        int numVertices;
        Vertex **adjList;
        int **adjMatrix;
        int head;

    public:
        Directed_Graph(int numVertices){
            this->numVertices = numVertices;
            adjMatrix = new int*[numVertices];
            adjList = new Vertex *[numVertices];
            for (int i = 0; i < numVertices; i++){
                adjList[i] = nullptr;
            }
            for (int i = 0; i < numVertices; i++){
                adjMatrix[i] = new int [numVertices];
                }
            for (int i = 0; i < numVertices; i++){
                for (int j = 0; j < numVertices; j++){
                    if (i==j){
                        adjMatrix[i][j] = 0;
                    }
                    else{
                        adjMatrix[i][j] = std::numeric_limits<int>::max();
                    }

                }
            }
            head = 0;
        }

    int get_index_from_adjlist(int u);
    bool isEmpty();
    void addEdge(int u, int v, int weight);
    void addVertex(int data);
    void deleteVertex(int data);
    void deleteEdge(int u, int v);
    void printGraph();
    void initialize_single_source(int data);
    int weight(int u, int v);
    void relax(int u, int v);
    int get_num_edges();
    bool Bellman_Ford_algo(int s);
    void Bellman_Ford(int s);
    bool check_negative_weights();
    Vertex **Dijkstra_algo(int s);
    void Dijkstra(int s);
    int **Floyd_Warshall_algo();
    void Floyd_Warshall();
    void compare_performance();
    void example_Dijkstra();
    void example_Bellman();
    void example_Floyd();
    void compare_performance_predefined();

};
#endif
