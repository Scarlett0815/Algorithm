#include <iostream>

using namespace std;

int ith;

int Partition(int a[], int l, int r){
    int x = a[r];
    int posi = l;
    for (int i = l;i <= r - 1;i ++){
        if (x > a[i]){
            int temp = a[posi];
            a[posi] = a[i];
            a[i] = temp;
            posi ++;
        }
    }
    a[r] = a[posi];
    a[posi] = x;
    return posi;
}

void RandomizedSelect(int a[], int l, int r, int fi){
    int k = Partition(a, l, r);
    //if (k <= 3)
        //cout << k << endl;
    if (k == fi){
        ith = a[k];
    }
    else if (k < fi){
        //cout << "!\n";
        RandomizedSelect(a, k + 1, r, fi);
    }
    else{
        RandomizedSelect(a, l, k - 1, fi);
    }
    return;
}

int main(){
    int n;
    int fi;
    cin >> n >> fi;
    int a[n];
    for (int i = 0;i < n;i ++){
        cin >> a[i];
    }
    RandomizedSelect(a, 0, n - 1, fi - 1);
    cout << ith << endl;
}