#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;


int min(int x, int y) {
    return x < y ? x : y;
}
void merge_sort(int arr[], int num[],int len) {
    int *a = arr;
    int *num1 = num;
    int *b = (int *) malloc(len * sizeof(int));
    int *c = (int *) malloc(len * sizeof(int));
    int seg, start;
    for (seg = 1; seg < len; seg += seg) {
        for (start = 0; start < len; start += seg * 2) {
            int low = start, mid = min(start + seg, len), high = min(start + seg * 2, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2){
                if (a[start1] < a[start2]){
                    b[k] = a[start1];
                    c[k] = num1[start1];
                    start1 ++;
                }
                else if (a[start1] > a[start2]){
                    b[k] = a[start2];
                    c[k] = num1[start2];
                    start2++;
                }
                else if (a[start1] == a[start2]){
                    if (num1[start1] >= num1[start2]){
                        b[k] = a[start2];
                        c[k] = num1[start2];
                        start2++;
                    }
                    else{
                        b[k] = a[start1];
                        c[k] = num1[start1];
                        start1 ++;
                    }
                }
                k ++;
            }
            while (start1 < end1){
                b[k++] = a[start1++];
                c[k - 1] = num1[start1 - 1];
            }
            while (start2 < end2){
                b[k++] = a[start2++];
                c[k - 1] = num1[start2 - 1];
            }
        }
        int *temp = a;
        int *temp1 = num1;
        a = b;
        num1 = c;
        c = temp1;
        b = temp;
    }
    if (a != arr) {
        int i;
        for (i = 0; i < len; i++){
            b[i] = a[i];
            c[i] = num1[i];
        }
        b = a;
        c = num1;
    }
    free(b);
    free(c);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    int b[n];
    memset(b,0,sizeof(b));
    for (int i = 0;i < n;i ++) cin >> a[i];
    sort(a,a + n);
    int index = 0;
    for (int i = 0;i < n;i ++){
        if (a[i] != a[index]){
            index ++;
            a[index] = a[i];
            b[index] ++;
        }
        else {
            b[index] ++;
        }
    }
    merge_sort(b,a,index + 1);
    for (int i = 0;i < index + 1;i ++){
        for (int j = 0;j < b[i];j ++){
            cout << a[i] << ' ';
        }
    }
    return 0;
}