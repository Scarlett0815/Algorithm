#include <iostream>
#include <cstdio>
#include <map>

using namespace std;
map<string, int> container;

void Insert(){
    string name;
    int key;
    cin >> key;
    cin >> name;
    container.insert(pair <string, int> (name, key));
    return;
}

void Find(){
    string name;
    cin >> name;
    map<string, int> ::iterator l_it;
    l_it = container.find(name);
   if(l_it != container.end())
        cout<<l_it -> second <<endl;
   else{
        cout << "-1\n";
   }
    return;
}

int main(){
    while(1){
        string op;
        cin >> op;
        //cout << op << endl;
        if (op == "INSERT"){
            Insert();
        }
        else if (op == "FIND"){
            Find();
        }
        else if (op== "EXIT"){
            break;
        }
    }
    return 0;
}
