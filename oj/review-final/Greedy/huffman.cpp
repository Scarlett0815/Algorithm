#include <iostream>
#include <map>

using namespace std;

struct Node{
    int fre;
    struct Node* lchild;
    struct Node* rchild;
};

int n;

struct Node* CreateHuffmanTree(multimap<int, struct Node*> nmap){
    if (nmap.size() == 1){
        return nmap.begin() -> second;
    }
    auto min_leaf = nmap.begin();
    struct Node* leaf = new struct Node;
    leaf -> lchild = min_leaf -> second;
    leaf -> fre = min_leaf -> second -> fre;
    nmap.erase(min_leaf -> first);
    min_leaf = nmap.begin();
    leaf -> rchild = min_leaf -> second;
    leaf -> fre += min_leaf -> second -> fre;
    nmap.erase(min_leaf -> first);
    nmap.insert({leaf -> fre, leaf});
    return CreateHuffmanTree(nmap);
}


void Print(struct Node* print_point, int depth){
    if (print_point == NULL){
        return;
    }
    else{
        for (int i = 0;i < depth;i ++){
            cout << ' ';
        }
        cout << print_point -> fre << endl;
        Print(print_point -> lchild, depth + 1);
        Print(print_point -> rchild, depth + 1);
        return;
    }
    return;
}

int main(){
    multimap<int, struct Node*> nmap;
    cin >> n;
    for (int i = 0;i < n;i ++){
        struct Node* leaf = new struct Node;
        cin >> leaf -> fre;
        leaf -> lchild = NULL;
        leaf -> rchild = NULL;
        nmap.insert({leaf -> fre, leaf});
    }
    struct Node* root = CreateHuffmanTree(nmap);
    //cout << "Create Success!\n";
    Print(root, 0);
    return 0;
}