#include <iostream>
#include <set>
#include <map>

using namespace std;

int n;
int m;

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
        graph[node_end][node_begin] = weight;
    }
    return;
}

int Prims(){
    int mst = 0;
    invertice.insert(0);
    for (int i = 1;i < n;i ++){
        outvertice.insert(i);
    }
    multimap<int, int> minmap;
    for (int i = 1;i < n;i ++){
        minmap.insert({graph[0][i], i});
    }
    while (outvertice.size()){
        int min_edge = minmap.begin() -> first;
        auto iter_begin = minmap.begin();
        int new_vertex = iter_begin -> second;
        invertice.insert(new_vertex);
        outvertice.erase(new_vertex);
        mst += min_edge;
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
    return mst;
}

int main(){
    cin >> n;
    cin >> m;
    CreateGraph();
    int mst = Prims();
    cout << mst << endl;
    return 0;
}