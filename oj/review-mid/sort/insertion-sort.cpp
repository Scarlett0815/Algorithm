#include <iostream>

using namespace std;

void InsertionSort(int a[],int n){
    for (int i = 0;i < n;i ++){
        for (int j = 0;j < i;j ++){
            if (a[i] <= a[j]){
                int temp = a[i];
                for (int k = i - 1;k >= j;k --){
                    a[k + 1] = a[k];
                }
                a[j] = temp;
                break;
            }
        }
    }
    return;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0;i < n;i ++){
        cin >> a[i];
    }
    InsertionSort(a, n);
    for (int i = 0;i < n;i ++){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}