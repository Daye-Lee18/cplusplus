#pragma once

#include "graph.h"
#include <map>

// bfs는 보통 source로부터 distance (depth) 를 구할 때 
// 첫번째 인자로 BFS를 시작할 vertex 인스턴스를 입력받음 
// 두번째 인자로 search한 vertex들의 distance를 저장 
void BFS(Vertex* start,
    std::map<Vertex*, unsigned int> &distance);

// dfs는 algorithm의 subroutine으로 예를 들어, topological sort를 위해 사용됨 
// 첫번째 인자로 DFS를 시작할 vertex 인스턴스, 두번째 인자로 discovery time과 finishing time 기록을 위한 time 입력 
// 세번째 인자로 search한 vertex들의 discovery time을 저장, 네번째 인자에 search 한 finishing time을 저장 
void DFS(Vertex* vertex, unsigned int &timestamp,
    std::map<Vertex*, unsigned int> &discovery_time,
    std::map<Vertex*, unsigned int> &finishing_time);
