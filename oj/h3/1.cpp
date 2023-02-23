#include <iostream>

using namespace std;

long long _map[1000000];


long long FindMax(int n,long long maxval, int a[]){
    //cout << maxval;
    for (int i = 1;i < n;i ++){
        if (_map[i-1] > 0){
            _map[i] = a[i] + _map[i - 1];
        }
        else{
            _map[i] = a[i];
        }
        if (maxval < _map[i]) maxval = _map[i];
    }
    return maxval;
}

int main(){
    int n;
    long long maxval;
    int a[1000000];
    scanf("%d", &n);
    maxval = -1203988340;
    for (int i = 0;i < n;i ++){
        scanf("%d", &a[i]);
        if (a[i] > maxval){
            maxval = a[i];
        }
    }
    _map[0] = a[0];
    cout << FindMax(n, maxval, a);
    //cout << a[8];
}

//2^long