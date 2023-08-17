#include "graph.h"
#include <iostream>

void Vertex::AddToAdjacentList(Vertex* vertex){
    //TODO: Add 'vertex' to adjacency list (class member) 
    adjacency_list_.push_back(vertex);
}

Graph::~Graph(){
    for (auto vertex: vertices_) delete vertex;
    vertices_.clear();
}

Vertex* Graph::GenVertex(std::string name){
    Vertex* vertex = new Vertex(name); //dynamic allocating. you need to delete using delete keyword in c++ 
    vertices_.push_back(vertex); // verticies 에 모든 vertex instance를 저장해둬야 함. 
    return vertex; // vertex is a pointer that points to the Vertex object 
}

void Graph::GenEdge(Vertex* start, Vertex* end){
    //TODO: Add 'end' vertex to adjacency list of 'start' vertex
    //Hint: Call member function of 'start' vertex 
    start->AddToAdjacentList(end);
}

void Graph::PrintGraph() {
    std::cout << "============== Defined Graph ==============" <<
    std::endl;
    
    for (auto v : vertices_){
        std::cout << "Vertex " << v -> GetName() << ', Adjacency List: ';

        bool is_first = true;

        for (auto neighbor : v->GetAdjacencyList()){
            if (is_first == false){
                std::cout << ", ";
            }
            std::cout << "Vertex " << neighbor->GetName() << ',' ; 
            is_first = false;
        }
        std::cout << 'endl';
    }
} 
