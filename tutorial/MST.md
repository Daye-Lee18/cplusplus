# MST (Minimum Spanning Tree)

- purpose: to find the MST of a connected, undirected graph 
- MST :
  - A subset of the edges that connects all the vertices in a graph with the minimum possible total edge weight 
  
## Prim's Algorithm 

- starting from an arbitrary vertex and adding the cloest edge at each step 
- grows the MST one vertext at a time 
- 2 sets 
  - the set of vertices included in the MST (`MSTSet`)
  - the set of vertices not yet included (`remainingSet`)
- algorithm 
  - starts by adding an initial vertex to `MSTSet` and initializes the distances of all other vertices to a large value 
  - at each step, the algorithm selects the vertex with the minimum distance from `MSTSet` and adds it to the set. 
  - Updates the distance of its neighboring vertices if they can be reached with a smaller edge weight 

```c++
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;  // Pair of vertex and weight

class Graph {
    int V;  // Number of vertices
    vector<vector<pii>> adj;  // Adjacency list

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void primMST();
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
}

void Graph::primMST() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;  // Min-heap
    vector<int> key(V, INT_MAX);  // Key values to track minimum edge weights
    vector<int> parent(V, -1);  // Parent array to store MST

    int src = 0;  // Start from vertex 0
    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (key[v] > weight) {
                pq.push(make_pair(weight, v));
                key[v] = weight;
                parent[v] = u;
            }
        }
    }

    // Print the MST edges
    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << endl;
    }
}

int main() {
    int V = 5;  // Number of vertices
    Graph g(V);

    // Adding edges to the graph
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.primMST();

    return 0;
}



```


## Krustkal's Algorithm 