#include <iostream>

using namespace std;

// the leaves are all the dummy ones
// be careful with the boundary constraints

int n;
float p[101];
float q[101];
float fresum[101][101];
float mmap[101][101];

void FindOptimalBinaryTree(){
    for (int i = 0;i <= n;i ++){
        for (int j = i + 1;j <= n;j ++){
            mmap[i][j] = 100;
        }
    }
    for (int i = 0;i <= n;i ++){
        mmap[i][i] = q[i];
    }
    for (int l = 0;l <= n;l ++){
        for (int i = 0;i <= n - l;i ++){
            if (l == 0){
                fresum[i][i] = q[i];
            }
            else{
                fresum[i][i + l] = fresum[i][i + l - 1] + p[i + l] + q[i + l];
            }
        }
    }

    for (int l = 1;l <= n;l ++){
        for (int i = 0;i <= n - l;i ++){
            for (int k = i + 1;k <= i + l;k ++){
                if (mmap[i][k - 1] + mmap[k][i + l] + fresum[i][k - 1] + fresum[k][i + l] + p[k] < mmap[i][i + l]){
                    mmap[i][i + l] = mmap[i][k - 1] + mmap[k][i + l] + fresum[i][i + l];
                }
            }
        }
    }
    return;
}

int main(){
    cin >> n;
    for (int i = 1;i <= n;i ++){
        cin >> p[i];
    }
    for (int i = 0;i <= n;i ++){
        cin >> q[i];
    }
    FindOptimalBinaryTree();
    cout << mmap[0][n] << endl;
    return 0;
}