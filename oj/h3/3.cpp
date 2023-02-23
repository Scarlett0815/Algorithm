#include <iostream>
#include <algorithm>

using namespace std;

struct Product{
    int weight;
    int value;
    int num;
};

int main(){
    struct Product pro[202];
    int n;
    int W;
    cin >> n >> W;
    int max_value[n + 1][W + 1];
    for (int i = 0;i < n;i ++){
        cin >> pro[i + 1].weight >> pro[i + 1].value >> pro[i + 1].num;
    }
    for (int i = 0;i <= W;i ++){
        max_value[0][i] = 0;
    }
    for (int i = 1;i <= n;i ++){
        for (int w = 0;w <= W;w ++){
            max_value[i][w] = max_value[i - 1][w];
            for (int k = 1;k <= pro[i].num;k ++){
                if (w - k * pro[i].weight >= 0)
                    max_value[i][w] = max(max_value[i - 1][w - k * pro[i].weight] + k * pro[i].value, max_value[i][w]);
                else break;
            }
        }
    }
    cout << max_value[n][W];
}