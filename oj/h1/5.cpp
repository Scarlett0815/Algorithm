#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0;i < n;i ++){
        cin >> a[i];
    }
    sort(a, a + n);
    int b[n + 1];
    for (int i = 0;i < n;i ++){
        b[i + 1] = a[n - i - 1];
    }
    int l = 1;
    int r = n;
    int mid = (l + r) / 2;
    int flag = 0;
    while (l <= r){
        if (b[mid] == mid){
           printf ("%d",mid);
           flag = 1;
           break;
        }
        else if (b[mid] > mid){
            if (b[mid + 1] <= mid){
                printf ("%d", mid);
                flag = 1;
                break;
            }
            else {
                l = mid + 1;
                r = r;
                mid = (l + r) / 2;
            }
        }
        else {
            if (b[mid - 1] >= mid){
                printf ("%d",mid - 1);
                flag = 1;
                break;
            }
            else {
                l = l;
                r = mid;
                mid = (l + r) / 2;
            }
        }
    }
    if (!flag) cout << mid;
}