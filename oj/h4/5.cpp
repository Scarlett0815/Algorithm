#include <iostream>
#include <cstring>

using namespace std;

int n;

void cal_next(string ptr, int pi[])
{
    int plen = ptr.length();
    pi[0] = -1;
    int k = -1;
    for (int q = 1; q <= plen-1; q++)
    {
        while (k > -1 && ptr[k + 1] != ptr[q])
        {
            k = pi[k];
        }
        if (ptr[k + 1] == ptr[q])
        {
            k = k + 1;
        }
        pi[q] = k;
    }
    return;
}

int KMP(string str, string ptr)
{
    int plen = ptr.length();
    int pi[plen];
    cal_next(ptr, pi);
    int k = -1;
    int slen = str.length();
    int index = 0;
    for (int i = 0; i < slen; i++)
    {
        while (k > -1 && ptr[k + 1] != str[i])
            k = pi[k];
        if (ptr[k + 1] == str[i])
            k = k + 1;
        if (k == plen-1)
        {
            index ++;
            k = pi[k];
        }
    }
    return index;
}

int main(){
    scanf("%d", &n);
    string p;
    string s;
    for (int i = 0;i < n;i ++){
        cin >> p;
        cin >> s;
        cout << KMP(s, p) << endl;
    }
}