#pragma once 

#include <string> 
#include <vector> // python에서 list 와 동일 
using namespace std;


//vertex class 
class Vertex {
    private:
        string name_;
        vector<Vertex*> adjacency_list_;
    public:    
        Vertex(string name){
            name_ = name ;
        }

        string GetName(){
            return name_;
        }

        vector<Vertex*> GetAdjacencyList(){
            return adjacency_list_;
        }

        void AddToAdjacentList(Vertex* vertex);
        
        
};

//Graph class 
class Graph{
    private:
        vector<Vertex*> vertices_; // Graph 내의 모든 vertex instance를 저장해두는 리스트 
    public:
        Graph() {} //constructor 
        ~Graph(); //destructor 

        Vertex* GenVertex(string name); // Vertex instance 생성, member data인 vertices에 생성한 instance 저장 
        void GenEdge(Vertex* start, Vertex* end); // start vertex의 adjacency list에 end vertex를 추가 
        
        vector<Vertex*> GetVertices(){
            return vertices_;
        } // Graph내의 모든 vertex instance를 담고 있는 리스트를 반환 
        
        //std::size_t : unsigned int로 array 등의 길이를 구할때 보통 사용한다. 
        size_t GetNumVertices(){
            return vertices_.size();
        } // Graph 내의 모든 vertex 개수를 리턴 

        void PrintGraph(); // graph내의 모든 vertex의 이름과 각각의 adjacency list를 출력 

};
