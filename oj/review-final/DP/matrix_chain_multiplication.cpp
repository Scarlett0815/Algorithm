#include <iostream>

using namespace std;

int n;// assume n <= 100
int p[101];
int minc[101][101];

int ComputingOptimalCost(){
    for (int i = 0;i <= n;i ++){
        for (int j = i + 1;j <= n;j ++){
            minc[i][j] = 100000000;
        }
    }
    for (int l = 1;l <= n - 1;l ++){
        for (int i = 1;i <= n - l;i ++){
            for (int k = i;k <= i + l - 1;k ++){
                if (minc[i][k] + minc[k + 1][i + l] + p[i - 1] * p[k] * p[i + l] < minc[i][i + l]){
                    minc[i][i + l] = minc[i][k] + minc[k + 1][i + l] + p[i - 1] * p[k] * p[i + l];
                    //cout << ' ' << minc[i][i + l] << endl;
                }
            }
            //cout << minc[i][i + l] << endl;
        }
    }
    return minc[1][n];
}

int main(){
    cin >> n;
    for (int i = 0;i <= n;i ++){
        cin >> p[i];
    }
    int opt_cost = ComputingOptimalCost();
    cout << opt_cost << endl;
}