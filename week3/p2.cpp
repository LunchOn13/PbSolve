#include <iostream>
#include <cstring>
#include <vector>
#define MAX 100001

using namespace std;

int v;
vector<pair<int, int>> graph[MAX];
bool visited[MAX];
int diameter, farthest_node; // 지름, 루트에서 가장 먼 노드

void dfs(int node, int cost){
    if(visited[node]) return;
    visited[node] = true;
    
    // 지름 업데이트
    if(diameter < cost) {
        diameter = cost;
        farthest_node = node;
    }
    
    for(int i=0; i<graph[node].size(); i++){
        dfs(graph[node][i].first, cost + graph[node][i].second);
    }
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> v;
    while(v--){
        int node;
        cin >> node;
        while(true){
            int node2, cost;
            cin >> node2;
            if(node2 == -1) break;
            cin >> cost;
            
            graph[node].push_back(make_pair(node2, cost));
        }
    }
    
    // 루트에서 가장 먼 정점 찾기
    memset(visited, false, sizeof(visited));
    dfs(1, 0);
    
    // 가장 먼 정점에서 탐색 시작
    memset(visited, false, sizeof(visited));
    diameter = 0; // 초기화
    dfs(farthest_node, 0);
    
    cout << diameter << '\n';
    
    return 0;
}