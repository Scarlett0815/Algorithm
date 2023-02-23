#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    map<int, int> m;
    int n;
    map<int, int>::iterator pre_it;
    cin >> n;
    int key_up, key_low;
    cin >> key_low >> key_up;
    m.insert(pair<int, int>(key_up, key_low));
    cout << 0 << endl;
    for (int i = 1; i < n; i++)
    {
        cin >> key_low >> key_up;
        pre_it = m.lower_bound(key_low);
        if (pre_it == m.end()){
            cout << 0 << endl;
            m.insert(pair<int, int>(key_up, key_low));
        }
        else if (key_up < pre_it -> second)
        {
            cout << 0 << endl;
            m.insert(pair<int, int>(key_up, key_low));
        }
        else {
            cout << -1 << endl;
        }
    }
}