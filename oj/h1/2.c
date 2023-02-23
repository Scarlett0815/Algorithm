#include <stdio.h>
#include <string.h>

int main(){
    long long n;
    scanf("%lld",&n);
    int b[n + 1];
    memset(b, 0, sizeof(b));
    for (long long i = 0;i < n;i ++){
        long long t;
        scanf("%lld",&t);
        b[t] = 1;
    }
    for (long long i = 0;i < n;i ++){
        if (b[i] == 0){
            printf("%lld",i); break;
        }
    }
    return 0;
}