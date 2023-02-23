#include <iostream>
#include <map>

using namespace std;

string arr[10002];

bool Max(string a, string b){
    if (a + b > b + a)
        return true;
    else
        return false;
}

int Partition(string a[], int l, int r){
    string x = a[r];
    int i = l;
    for (int j = l;j < r;j ++){
        if (Max(a[j], x)){
            string temp = a[j];
            a[j] = a[i];
            a[i] = temp;
            i ++;
        }
    }
    a[r] = a[i];
    a[i] = x;
    return i;
}

void QuickSort(string a[], int l, int r){
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
        arr[i] = to_string(a[i]);
    }
    QuickSort(arr, 0, n - 1);
    for (int i = 0;i < n;i ++){
        cout << arr[i];
    }
    //cout << endl;
    return 0;
}
