#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int n, m, s, t;
int graph[502][502];
int rgraph[502][502];

bool BFS(int parent[])
{
    bool visited[502];
    memset(visited, 0, sizeof(visited));

    queue<int> inter;
    inter.push(s);
    visited[s] = true;
    parent[s] = 0;

    int u;
    while (!inter.empty())
    {
        u = inter.front();
        inter.pop();
        for (int v = 1; v < 502; v ++)
        {
            if (!visited[v] && rgraph[u][v] != 0)  // find one linked vertex
            {
                inter.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[t];
}

int main(){
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 0;i < m;i ++){
        int u, v, l;
        scanf("%d%d%d", &u, &v, &l);
        graph[u][v] += l;
        rgraph[u][v] += l;
    }

    int parent[502];
    memset(parent, 0, sizeof(parent));
    int max_flow = 0;

    while(BFS(parent)){
        int path_flow = 1000000;
        int v = t;
        while (v != s){
            int u = parent[v];
            path_flow = min(path_flow, rgraph[u][v]);
            v = u;
        }
        v = t;
        while (v != s){
            int u = parent[v];
            rgraph[u][v] -= path_flow;
            rgraph[v][u] += path_flow;
            v = u;
        }
        max_flow += path_flow;
    }
    cout << max_flow << endl;
}