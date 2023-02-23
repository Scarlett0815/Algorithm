#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

struct Edge{
    int vbegin;
    int vend;
    int cost;
};

int n;
int m;
set<int> vertice;
multimap<int, struct Edge *> mmap;

int main(){
    scanf("%d%d",&n, &m);
    for (int i = 0;i < m;i ++){
        int x_i;
        int x_j;
        int cost;
        scanf("%d%d%d",&x_i, &x_j, &cost);
        struct Edge *e = new struct Edge;
        if (x_i < x_j){
            e -> vbegin = x_i;
            e -> vend = x_j;
        }
        else{
            e -> vbegin = x_j;
            e -> vend = x_i;
        }
        e -> cost = cost;
        mmap.insert({cost, e});
        if (vertice.find(x_i) == vertice.end()){
            vertice.insert(x_i);
        }
        if (vertice.find(x_j) == vertice.end()){
            vertice.insert(x_j);
        }
    }
    int total_cost = 0;
    int vertex_number = vertice.size();
    int vertex_begin = *(vertice.begin());
    set<int> inter = {vertex_begin};
    set<int> exter = vertice;
    exter.erase(vertex_begin);
    while (inter.size() < vertex_number){
        //cout << inter.size() << endl;
        auto iter = mmap.begin();
        while (iter != mmap.end()){
            if (inter.find(iter -> second -> vbegin) != inter.end()){
                if (inter.find(iter -> second -> vend) != inter.end()){
                    //cout << "hello" << endl;
                    iter = mmap.erase(iter);
                    continue;
                }
                else{
                    //cout << "hello1" << endl;
                    exter.erase(iter -> second -> vend);
                    inter.insert(iter -> second -> vend);
                    total_cost += iter -> first;
                    //cout << iter -> first << endl;
                    break;
                }
            }
            else if (inter.find(iter -> second -> vbegin) == inter.end()){
                //cout << "hello2" << endl;
                if (inter.find(iter -> second -> vend) != inter.end()){
                    exter.erase(iter -> second -> vbegin);
                    inter.insert(iter -> second -> vbegin);
                    total_cost += iter -> first;
                    break;
                }
                //cout << "hello3" << endl;
            }
            //cout << "hello4" << endl;
            iter ++;
        }
    }
    cout << total_cost;
    return 0;
}