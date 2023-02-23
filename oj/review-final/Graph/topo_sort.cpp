#include <iostream>
#include <map>
#include <stack>

using namespace std;

struct Arc{
    int adjnode;
    int weight;
    struct Arc* next;
};

struct Node{
    int key;
    struct Arc* first;
};

int n;
int node_index;
struct Node node[100];
int visited[100];
stack<int> topostack;

void CreateGraph(){
    map<int, int> nodemap = {};
    for (int i = 0;i < n;i ++){
        int node_begin, node_end, weight;
        cin >> node_begin;
        cin >> node_end;
        cin >> weight;
        if (nodemap.find(node_begin) == nodemap.end()){
            node[node_index].key = node_begin;
            //cout << node_begin << endl;
            node[node_index].first = nullptr;
            nodemap[node_begin] = node_index;
            node_index ++;
        }
        if (nodemap.find(node_end) == nodemap.end()){
            node[node_index].key = node_end;
            //cout << node_end << endl;
            node[node_index].first = nullptr;
            nodemap[node_end] = node_index;
            node_index ++;
        }
        struct Arc* new_arc = new struct Arc;
        new_arc -> adjnode = nodemap[node_end];
        new_arc -> weight = weight;
        new_arc -> next = node[nodemap[node_begin]].first;
        node[nodemap[node_begin]].first = new_arc;
    }
    return;
}

void Visit(int node_order){
    visited[node_order] = 1;
    return;
}

void TopoSort(int node_order){
    Visit(node_order);
    for (struct Arc* arc = node[node_order].first; arc != nullptr; arc = arc -> next){
        if (visited[arc -> adjnode] == 0){
            TopoSort(arc -> adjnode);
            topostack.push(node[arc -> adjnode].key);
        }
    }
    return;
}

void Print(){
    while (topostack.size()){
        int elem = topostack.top();
        cout << elem << endl;
        topostack.pop();
    }
}

int main(){
    cin >> n;
    CreateGraph();
    for (int i = 0;i < node_index;i ++){
        if (visited[i] == 0){
            TopoSort(i);
            topostack.push(node[i].key);
        }
    }
    Print();
    return 0;
}