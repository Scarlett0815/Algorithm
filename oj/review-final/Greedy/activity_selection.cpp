#include <iostream>
#include <set>

using namespace std;

struct Activity{
    int s;
    int f;
    int number;
};

int n;
struct Activity a[100];
set<int> max_set = {};

int Partition(int l, int r){
    int x = a[r].f;
    int i = l;
    for (int j = l;j < r;j ++){
        if (a[j].f < x){
            struct Activity temp = a[j];
            a[j] = a[i];
            a[i] = temp;
            i ++;
        }
    }
    a[r].f = a[i].f;
    a[i].f = x;
    return i;
}

void QuickSort(int l, int r){
    int mid_point = Partition(l, r);
    if (l < mid_point - 1)
        QuickSort(l, mid_point - 1);
    if (r > mid_point + 1)
        QuickSort(mid_point + 1, r);
    return;
}

void FindMaxSubset(){
    QuickSort(0, n - 1);
    int end_time = 0;
    for (int i = 0;i < n;i ++){
        if (a[i].s > end_time){
            end_time = a[i].f;
            max_set.insert(a[i].number);
        }
    }
    return;
}

int main(){
    cin >> n;
    for (int i = 0;i < n;i ++){
        cin >> a[i].s;
        cin >> a[i].f;
        a[i].number = i + 1;
    }
    FindMaxSubset();
    for (int act: max_set){
        cout << act << ' ';
    }
    cout << endl;
}