#include <iostream>

using namespace std;

void SelectionSort(int a[], int n){
    for (int i = 0;i < n - 1;i ++){
        int min_pos = i;
        for (int j = i + 1;j < n;j ++){
            if (a[j] < a[min_pos]){
                min_pos = j;
            }
        }
        if (min_pos != i){
            int temp = a[i];
            a[i] = a[min_pos];
            a[min_pos] = temp;
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
    SelectionSort(a, n);
    for (int i = 0;i < n;i ++){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}