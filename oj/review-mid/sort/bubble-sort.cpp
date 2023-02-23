#include <iostream>

using namespace std;

void BubbleSort(int a[], int n){
    for (int i = 0;i < n;i ++){
        int flag = 1;
        for (int j = n - 1;j >= i;j --){
            if (a[j + 1] < a[j]){
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 0;
            }
        }
        if (flag == 1){
            break;
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
    BubbleSort(a, n);
    for (int i = 0;i < n;i ++){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}