#include <iostream>
#include <map>
#include <set>

using namespace std;

int n;
int m;
int s;
int t;

struct Edge{
    int vend;
    int cost;
};
int INF = 20000000;
int dis[100002];
map<int, set<struct Edge *>> graph;
multimap <int, int>d;

int main(){
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 0;i < m;i ++){
        int vbegin;
        int vend;
        int cost;
        scanf("%d%d%d", &vbegin, &vend, &cost);
        if (graph.find(vbegin) != graph.end()){
            struct Edge *e = new struct Edge;
            e -> vend = vend;
            e -> cost = cost;
            graph[vbegin].insert(e);
        }
        else{
            struct Edge *e = new struct Edge;
            e -> vend = vend;
            e -> cost = cost;
            graph[vbegin] = {e};
        }
    }
    
    set<int> inter = {s};
    set<int> exter = {};
    dis[s] = 0;
    for (int i = 1;i <= n;i ++){
        if (i != s){
            dis[i] = INF;
            exter.insert(i);
        }
    }
    for (auto e: graph[s]){
        d.insert({e -> cost, e -> vend});
    }
    //cout << d.size() << endl;
    while (inter.size() < n){
        //cout << exter.size() << endl;
        if (inter.find(t) != inter.end() || d.size() == 0){
            break;
        }
        int v_to_insert = 0;
        auto iter = d.begin();
        while (iter != d.end()){
            //cout << "hello " << endl;
            if (exter.find(iter -> second) == exter.end()){
                //cout << "hello2 " << endl;
                iter = d.erase(iter);
                continue;
            }
            else{
                //cout << "hello1 " << endl;
                v_to_insert = iter -> second;
                dis[v_to_insert] = iter -> first;
                d.erase(iter);
                break;
            }
        }
        //cout << v_to_insert << endl;
        if (v_to_insert){
            inter.insert(v_to_insert);
            exter.erase(v_to_insert);
            for (auto e: graph[v_to_insert]){
                if (exter.find(e -> vend) != exter.end()){
                    d.insert({dis[v_to_insert] + e -> cost, e -> vend});
                }
            }
        }
        //cout << d.size() << endl;
    }
    if (inter.find(t) != inter.end()){
        cout << dis[t];
    }
    else{
        cout << "-1";
    }
    return 0;
}