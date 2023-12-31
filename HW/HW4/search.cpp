#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include "search.h"


/*
BFS는 그래프를 breadth-search로 돌면서, start node로부터 거리를 저장하려고 한다. 
*/
void BFS(Vertex* start, std::map<Vertex*, unsigned int> &distance) {
  unsigned int curr;
  Vertex* vertex;
	std::queue<std::pair<Vertex*, unsigned int>> q;

  
  std::map<Vertex*, bool> visited; // boolean value is true when vertex is visited
  curr = 0; // root node has distance of zero
  visited[start] = true; // TODO: mark root node as visited

	q.push(std::make_pair(start, curr)); // push (root node, distance 0) pair to the queue


	while (q.empty() == false) {
    // lookup front of the queue
		vertex = q.front().first;
    curr = q.front().second;

    // TODO: pop out front of the queue
    q.pop();
    unsigned int adj_dist;
    adj_dist = curr + 1;

    for (auto adjacent : vertex->GetAdjacencyList()) {
      // when adjacent vertex is not yet visited
      if (visited[adjacent] == false) {
        // TODO: mark adjacent vertex as visited
        visited[adjacent] = true;

        // TODO: push (adjacent vertex, distance) pair to the queue
        q.push(std::make_pair(adjacent, adj_dist));
      }
    }

    // write distance of the vertex to the map
    distance[vertex] = curr;
	}
}

// discovery time: v.d records when v is first discovered (and grayed in color) 
// finishing_time: v.f records when the search finishes examining v's adjacency list (and blacked in color) 
void DFS(Vertex* vertex, unsigned int &timestamp,
    std::map<Vertex*, unsigned int> &discovery_time,
    std::map<Vertex*, unsigned int> &finishing_time) {
 
  timestamp += 1;  // TODO: increase timestamp for discovery time

  discovery_time[vertex] = timestamp; // TODO: store discovery time of current vertex

  // TODO: recursively call DFS for vertices in the adjancency list
  for(auto adjacent : vertex->GetAdjacencyList()){
    if(discovery_time.find(adjacent) == discovery_time.end()){ // adjacent가 discovery_time map에 없는 경우 ( = visit하지 않은 경우) 에만 dfs를 돌자 
      DFS(adjacent, timestamp, discovery_time, finishing_time);
    }
  }

  // increase timestamp for finishing time
  timestamp += 1;

  // store finishing time of current vertex
  finishing_time[vertex] = timestamp;
}
