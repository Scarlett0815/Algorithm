#include <iostream>
#include <cstring>
#include <map>
#include <math.h>
#include <stack>

using namespace std;

struct Items{
    int d_i;
    int d_j;
};



int n;
int m;
int a[100001];
int di;
int dj;
int abs_adi;
int abs_adj;
stack<int> group[20001];

multimap<int, struct Items, greater<int> > danger;

int main(){
    scanf("%d%d", &n, &m);
    //memset (a,0,sizeof(a));
    //cout << a[6] << ' ' << a[7] << endl;
    for (int i = 0;i < m;i ++){
        struct Items items;
        int a_i_j;
        scanf("%d%d%d", &items.d_i, &items.d_j, &a_i_j);
        danger.insert(pair<int, struct Items>(a_i_j, items));
    }
    multimap<int, struct Items>::iterator iter;
    int flag = 0;
    int index = 0;
    for (iter = danger.begin();iter != danger.end();iter++){
        di = iter -> second.d_i;
        dj = iter -> second.d_j;
        abs_adi = abs(a[di]);
        abs_adj = abs(a[dj]);
        if (index == 0){
            if (di == iter -> second.d_j){
                flag = 1;
                cout << iter -> first;
                //cout << "case1";
                break;
            }
            index ++;
            a[di] = -20000;
            a[dj] = 20000;
            group[0].push(di);
            group[0].push(dj);
        }
        else{
            if (di == dj){
                flag = 1;
                cout << iter -> first;
                //cout << "case2";
                break;
            }
            else{
                if (abs_adi && abs_adi == abs_adj){
                    if (a[di] == a[dj]){
                        flag = 1;
                        cout << iter -> first;
                        //cout << a[di] << endl;
                        //cout << "case3";
                        break;
                    }
                }
                else if (abs_adi > abs_adj){
                    int temp = a[dj];
                    a[dj] = - a[di];
                    int re_abs_adi = 20000 - abs_adi;
                    group[re_abs_adi].push(dj);
                    int order = 20000 - abs(temp);
                    int size = group[order].size();
                    while (size --){
                        int item = group[order].top();
                        if (a[item] == temp){
                            a[item] = -a[di];
                            group[re_abs_adi].push(item);
                        }
                        else if(a[item] == -temp){
                            a[item] = a[di];
                            group[re_abs_adi].push(item);
                        }
                        group[order].pop();
                    }
                    //Merge(temp,a[di]);
                }
                else if (abs_adi < abs_adj){
                    int temp = a[di];
                    a[di] = - a[dj];
                    int re_abs_adj = 20000 - abs_adj;
                    group[re_abs_adj].push(di);
                    int order = 20000 - abs(temp);
                    int size = group[order].size();
                    while (size --){
                        int item = group[order].top();
                        if (a[item] == temp){
                            a[item] = -a[dj];
                            group[re_abs_adj].push(item);
                        }
                        else if(a[item] == -temp){
                            a[item] = a[dj];
                            group[re_abs_adj].push(item);
                        }
                        group[order].pop();
                    }
                    //Merge(temp,a[dj]);
                }
                else{
                    int temp = 20000 - index;
                    a[di] = temp;
                    a[dj] = -temp;
                    group[index].push(di);
                    group[index].push(dj);
                    //cout << "group" << index << endl;
                    index ++;
                }
            }
        }
    }
    if (!flag){
        cout << "0";
    }
}