#include <iostream>

using namespace std;

int Partition(int a[], int l, int r){
    int x = a[r];
    int i = l;
    for (int j = l;j < r;j ++){
        if (a[j] < x){
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;
            i ++;
        }
    }
    a[r] = a[i];
    a[i] = x;
    return i;
}

void QuickSort(int a[], int l, int r){
    int mid_point = Partition(a, l, r);
    if (l < mid_point - 1)
        QuickSort(a, l, mid_point - 1);
    if (r > mid_point + 1)
        QuickSort(a, mid_point + 1, r);
    return;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0;i < n;i ++){
        cin >> a[i];
    }
    QuickSort(a, 0, n - 1);
    for (int i = 0;i < n;i ++){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}
