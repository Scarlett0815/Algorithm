#include <iostream>
#include <cstring>

using namespace std;

void CountingSort(int a[], int b[], int n){
    int c[10];
    memset(c, 0, sizeof(c));
    for (int i = 0;i < n;i ++){
        c[a[i]] ++;
    }
    for (int i = 1;i < 9;i ++){
        c[i] += c[i - 1];
    }
    for (int i = 9;i >= 1;i --){
        c[i] = c[i - 1];
    }
    c[0] = 0;
    for (int i = 0;i < n;i ++){
        b[c[a[i]]] = a[i];
        c[a[i]] ++;
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for (int i = 0;i < n;i ++){
        cin >> a[i];
    }
    CountingSort(a, b, n);
    for (int i = 0;i < n;i ++){
        cout << b[i] << ' ';
    }
    cout << endl;
    return 0;
}

