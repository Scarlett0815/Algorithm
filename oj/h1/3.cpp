#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    scanf("%d%d",&n, &m);
    long int a[n];
    long int b[m];
    for (int i = 0;i < n;i ++){
        scanf("%ld",&a[i]);
    }
    sort(a, a + n);
    for (int i = 0;i < m;i ++){
        scanf("%ld",&b[i]);
    }
    sort(b, b + m);
    int indexa = 0;
    int indexb = 0;
    int t = -1;
    for (int i;i < n + m;i ++){
        if (indexa == n || indexb == m) break;
        if (a[indexa] == b[indexb] && b[indexb] != t){
            printf("%ld ",a[indexa]);
            t = b[indexb];
            indexa ++;
            indexb ++;
        }
        else if (a[indexa] < b[indexb]){
            indexa ++;
        }
        else{
            indexb ++;
        }
    }
    if (t == -1) printf ("-1");
}