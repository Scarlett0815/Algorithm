#include <iostream>
#include <set>
#include <map>

using namespace std;

int n;
int m;
int s;
int t;

int dis[101];
set<int> invertice;
set<int> outvertice;
int graph[101][101];

void CreateGraph(){
    for (int i = 0;i < n;i ++){
        for (int j = 0;j < n;j ++){
            graph[i][j] = 1000000;
        }
    }
    for (int i = 0; i < m;i ++){
        int node_begin, node_end, weight;
        cin >> node_begin >> node_end >> weight;
        graph[node_begin][node_end] = weight;
    }
    return;
}

void Dijkstra(){
    invertice.insert(s);
    for (int i = 0;i < n;i ++){
        if (i != s)
            outvertice.insert(i);
    }
    multimap<int, int> minmap;
    for (int i = 0;i < n;i ++){
        minmap.insert({graph[s][i], i});
    }
    for (int i = 0;i < n;i ++){
        if (graph[s][i] + dis[s] < dis[i]){
            dis[i] = graph[s][i] + dis[s];
        }
    }
    while (outvertice.size()){
        int min_edge = minmap.begin() -> first;
        auto iter_begin = minmap.begin();
        int new_vertex = iter_begin -> second;
        for (int i = 0;i < n;i ++){
            if (graph[new_vertex][i] + dis[new_vertex] < dis[i]){
                dis[i] = graph[new_vertex][i] + dis[new_vertex];
            }
        }
        invertice.insert(new_vertex);
        outvertice.erase(new_vertex);
        minmap.erase(iter_begin);
        auto iter = minmap.begin();
        set<pair<int, int>> value_to_be_update;
        while (iter != minmap.end()){
            if (graph[new_vertex][iter -> second] < iter -> first){
                value_to_be_update.insert({graph[new_vertex][iter -> second], iter -> second});
                iter = minmap.erase(iter);
                continue;
            }
            iter ++;
        }
        for (auto p: value_to_be_update){
            minmap.insert(p);
        }
    }
    return;
}

int main(){
    cin >> n;
    cin >> m;
    CreateGraph();
    cin >> s >> t;
    for (int i = 0;i < n;i ++){
        dis[i] = 1000000;
    }
    dis[s] = 0;
    Dijkstra();
    cout << dis[t] << endl;
    return 0;
}