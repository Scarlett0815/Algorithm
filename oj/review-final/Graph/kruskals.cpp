#include <iostream>
#include <map>
#include <set>

using namespace std;

int n;
int m;
multimap<int, pair<int, int>> fulledges;
int father[101];

void CreateGraph(){
    for (int i = 0;i < m;i ++){
        int weight;
        int node_begin;
        int node_end;
        cin >> node_begin >> node_end;
        cin >> weight;
        fulledges.insert({weight, {node_begin, node_end}});
    }
    return;
}

int FindSet(int x){
    if (father[x] == x) return x;
    int res = FindSet(father[x]);
    father[x] = res;
    return res;
}

void MergeSet(int x1, int x2){
    int f1 = FindSet(x1);
    int f2 = FindSet(x2);
    if (f1 < f2){
        father[f2] = f1;
    }
    else{
        father[f1] = f2;
    }
    return;
}

int Kruskal(){
    //sort the edges
    int mst = 0;
    for (int i = 0;i < n;i ++){
        father[i] = i;
    }
    int edge_index = 0;
    for (auto elem: fulledges){
        if (edge_index == n - 1) break;
        pair<int, int> edge = elem.second;
        int f1 = FindSet(edge.first);
        int f2 = FindSet(edge.second);
        if (f1 != f2){
            edge_index ++;
            MergeSet(edge.second, edge.first);
            mst += elem.first;
            //cout << f1 << ' ' << f2 << ' ' << elem.first << endl;
        }
    }
    return mst;
}

int main(){
    cin >> n;
    cin >> m;
    CreateGraph();
    int mst = Kruskal();
    cout << mst << endl;
    return 0;
}