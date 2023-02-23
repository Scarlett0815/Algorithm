#include <iostream>
#include <algorithm>

using namespace std;

short a[2100][2100];
short bsquare[2100][2100];

int main(){
    int n, m;
    int index = 0;
    scanf("%d%d",&n,&m);
    for (int i = 0;i < n;i ++){
        for (int j = 0;j < m;j ++){
            scanf("%d",&a[i][j]);
            a[i][j] = 1 - a[i][j];
        }
    }
    for (int i = 0;i < n;i ++){
        for (int j = 0;j < m;j ++){
            bsquare[i][j] = a[i][j];
            index += bsquare[i][j];
        }
    }

    for (int r = 1;r < min(n, m);r ++){
        int flag = 0;
        for (int i = 0;i < n;i ++){
            for (int j = 0;j < m;j ++){
                for (int k1 = 0;k1 <= r;k1 ++) bsquare[i][j] = bsquare[i][j] & a[i + r][j + k1];
                for (int k1 = 0;k1 <= r;k1 ++) bsquare[i][j] = bsquare[i][j] & a[i + k1][j + r];
                if (bsquare[i][j]) flag = 1;
                index += bsquare[i][j];
            }
        }
        if (!flag) break;
    }
    cout << index;
    return 0;
}

//i i + r
//j j + r