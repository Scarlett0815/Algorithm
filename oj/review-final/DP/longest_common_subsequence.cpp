#include <iostream>
#include <string>
#include <algorithm>

#define LEFT 0
#define UP 1
#define UP_LEFT 2

using namespace std;

// this problem is a little different from the gold coin problem

int m, n;

int cmap[101][101];
int mmap[101][101];
short dmap[101][101];
string s, t;
char ls[100];

void FindLongestSubseqence(){
    for (int step = 2;step <= n + m; step ++){
        for (int i = max({step - n, 1});i <= min({m, step - 1});i ++){
            int up_left = mmap[i - 1][step - i - 1] + cmap[i][step - i];
            int up = mmap[i][step - i - 1];
            int left = mmap[i - 1][step - i];
            mmap[i][step - i] = max({up, left, up_left});
            if (mmap[i][step - i] == up){
                dmap[i][step - i] = UP;
            }
            else if (mmap[i][step - i] == left){
                dmap[i][step - i] = LEFT;
            }
            else{
                dmap[i][step - i] = UP_LEFT;
            }
        }
    }
    int length = mmap[m][n] - 1;
    //cout << length << endl;
    int x = m;
    int y = n;
    while ( x > 0 && y > 0){
        if (dmap[x][y] == LEFT){
            x --;
        }
        else if (dmap[x][y] == UP){
            y --;
        }
        else{
            ls[length] = s[x - 1];
            //cout << ls[length] << length << endl;
            x --;
            y --;
            length --;
        }
    }
    return;
}

int main(){
    cin >> s;
    cin >> t;
    m = s.length();
    n = t.length();
    for (int i = 0;i < m;i ++){
        for (int j = 0;j < n;j ++){
            cmap[i + 1][j + 1] = (s[i] == t[j]);
        }
    }
    FindLongestSubseqence();
    cout << ls << endl;
    return 0;
}