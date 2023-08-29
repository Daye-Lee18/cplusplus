#include <iostream>
#include <vector>
#include <algorithm> // sort 

using namespace std;

class Edge {
public:
    int src, dest, weight;

    Edge(int src, int dest, int weight) {
        this->src = src; // member variable이랑 parameter와 이름이 비슷해서 this을 이용해 구분해준 것 
        this->dest = dest;
        this->weight = weight;
    }
};

class Graph {
    int V;  // Number of vertices
    vector<Edge> edges;

public:
    Graph(int V);
    void addEdge(int src, int dest, int weight);
    vector<Edge> kruskalMST(); // vecotr: push_back (emplace_back), pop_back, insert, size, empty, clear, front, back, begin, end 
};

Graph::Graph(int V) {
    this->V = V;
}

void Graph::addEdge(int src, int dest, int weight) {
    edges.emplace_back(src, dest, weight);
}

//Edge 클래스는 src, dest, weight의 member variable이 있지만, 그 중 weight 에 의해 ascending하게 sort할 compare 함수를 생성 
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

vector<Edge> Graph::kruskalMST() {
    sort(edges.begin(), edges.end(), compareEdges); // vector<Edge>가 들은 edges들을 edge의 weight에 의해 ascending 순서로 나열, kruskal에서는 edge들을 minimum weight edge들을 순서대로 돌기 때문
    vector<Edge> result;

    vector<int> parent(V, -1); // parent에는 vertex의 개수만큼 -1로 initialziation을 해줌 

    
    for (const Edge& edge : edges) { // const 는 edge parameter를 해당 kruskalMST 함수내에서 modify하지 못하게끔 하고 (edge를 read-only parameter)변환 Edge& (reference)를 넘김으로써 또다른 copy를 만들지 않고 memory에 직접 가서 modify하게끔 한다. 
        int srcParent = parent[edge.src];
        int destParent = parent[edge.dest];

        if (srcParent != destParent) { // cycle 을 이루는지 확인 
            result.push_back(edge);
            parent[edge.dest] = edge.src;  // Union
        }
    }

    return result;
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

    vector<Edge> mst = g.kruskalMST();

    cout << "Minimum Spanning Tree Edges:" << endl;
    for (const Edge& edge : mst) {
        cout << edge.src << " - " << edge.dest << " (Weight: " << edge.weight << ")" << endl;
    }

    return 0;
}
