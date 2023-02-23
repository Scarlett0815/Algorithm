#include <iostream>

using namespace std;

void MergeSort(int a[],int result[],int begin,int end){
    int l = begin;
    int r = end;
    int mid = (l + r) / 2;
    if (l != r){
        MergeSort(a, result, l, mid);
        MergeSort(a, result, mid + 1, r);
    }
    int indexl = 0;
    int indexr = 0;
    for (int i = begin;i <= end;i ++){
        if (indexl <= mid - l && indexr <= r - mid - 1){
            if (a[l + indexl] < a[mid + 1 + indexr]){
                result[i] = a[l + indexl];
                indexl ++;
            }
            else{
                result[i] = a[mid + 1 + indexr];
                indexr ++;
            }
        }
        else if (indexl <= mid - l){
            result[i] = a[l + indexl];
            indexl ++;
        }
        else{
            result[i] = a[mid + 1 + indexr];
            indexr ++;
        }
    }
    for (int i = begin;i <= end;i ++){
        a[i] = result[i];
    }
    return;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    int result[n];
    for (int i = 0;i < n;i ++){
        cin >> a[i];
    }
    MergeSort(a,result, 0, n - 1);
    for (int i = 0;i < n;i ++){
        cout << result[i] << ' ';
    }
    cout << endl;
    return 0;
}