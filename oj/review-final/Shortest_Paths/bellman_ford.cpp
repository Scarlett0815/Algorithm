#include <iostream>
#include <map>

using namespace std;

int s, t;
int n, m;

int dis[101];
multimap<int, pair<int, int>> fulledges;

void CreateGraph(){
    for (int i = 0;i < m;i ++){
        int node_begin, node_end, weight;
        cin >> node_begin >> node_end >> weight;
        fulledges.insert({weight, {node_begin, node_end}});
    }
    return;
}

bool BellmanFord(){
    for (int i = 0;i < n - 1;i ++){
        for (auto edge: fulledges){
            int u = edge.second.first;
            int v = edge.second.second;
            if (dis[v] > dis[u] + edge.first){
                dis[v] = dis[u] + edge.first;
            }
        }
    }
    for (auto edge: fulledges){
        int u = edge.second.first;
        int v = edge.second.second;
        if (dis[v] > dis[u] + edge.first)
            return false;
    }
    return true;
}

int main(){
    cin >> n >> m;
    CreateGraph();
    cin >> s >> t;
    for (int i = 0;i < n;i ++){
        dis[i] = 1000000;
    }
    dis[s] = 0;
    if (BellmanFord()){
        cout << dis[t] << endl;
    }
    else{
        cout << "There is negative-weight cycle!\n";
    }
    return 0;
}