#include <iostream>
#include <cstring>

using namespace std;

void RadixSort(string a[], string b[], int n){
    int c[10];
    for (int i = 2;i >= 0;i --){
        memset(c, 0, sizeof(c));
        for (int j = 0;j < n;j ++){
            c[a[j][i] - '0'] ++;
        }
        for (int j = 1;j < 9;j ++){
            c[j] += c[j - 1];
        }
        for (int j = 9;j >= 1;j --){
            c[j] = c[j - 1];
        }
        c[0] = 0;
        for (int j = 0;j < n;j ++){
            b[c[a[j][i] - '0']] = a[j];
            c[a[j][i] - '0'] ++;
        }
        //cout << "circle" << 3 - i << endl;
        for (int j = 0;j < n;j ++){
            a[j] = b[j];
            //cout << b[j] << endl;
        }
    }
    return;
}

int main(){
    int n;
    cin >> n;
    string a[n];
    string b[n];
    for (int i = 0;i < n;i ++){
        cin >> a[i];
    }
    RadixSort(a, b, n);
    cout << endl;
    for (int i = 0;i < n;i ++){
        cout << a[i] << endl;
    }
    return 0;
}