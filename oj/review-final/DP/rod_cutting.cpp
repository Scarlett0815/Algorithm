#include <iostream>

using namespace std;

int n; // assume that n <= 100
int p[101];
int maxr[101];

int FindMaxPrice(){
    for (int i = 1; i <= n;i ++){
        for (int j = 0;j <= i;j ++){
            if (maxr[j] + p[i - j] > maxr[i]){
                maxr[i] = maxr[j] + p[i - j];
            }
        }
    }
    return maxr[n];
}

int main(){
    cin >> n;
    for (int i = 1;i <= n;i ++){
        cin >> p[i];
    }
    int max_revenue = FindMaxPrice();
    cout << "The max revenue is " << max_revenue << endl;
}