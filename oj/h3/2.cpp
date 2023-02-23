#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int m, n;
    int net[205][205];
    int min_net[205][205];
    cin >> n >> m;
    for (int i = 0;i < n;i ++){
        for (int j = 0;j < m;j ++){
            scanf("%d",&net[i + 1][j + 1]);
        }
    }
    min_net[1][0] = 0;
    for (int i = 2;i <= n;i ++){
        min_net[i][0] = min_net[i - 1][0] + net[i - 1][1];
    }
    min_net[0][1] = 0;
    for (int i = 2;i <= m;i ++){
        min_net[0][i] = min_net[0][i - 1] + net[1][i - 1];
    }
    for (int step = 2;step <= n + m;step ++){
        for (int i = 1;i <= step - 1;i ++){
            if(i <= n && step - i <= m){
                min_net[i][step - i] = min(min_net[i - 1][step - i] + net[i][step - i], min_net[i][step - i - 1] + net[i][step - i]);
                //cout << i << " " << step - i <<" " << min_net[i][step - i] << endl;
            }
        }
    }
    cout << min_net[n][m];
    return 0;
}