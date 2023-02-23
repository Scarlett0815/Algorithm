#include <iostream>

using namespace std;

struct Node{
    int key;
    struct Node *lchild;
    struct Node *rchild;
};

struct Node *TreeBuild(int pre_queue[], int mid_queue[], int n){
    if (n == 0){
        return NULL;
    }
    else{
        struct Node *root = new struct Node;
        root -> key = pre_queue[0];
        int l_mid_queue[n];
        int r_mid_queue[n];
        int l_i;
        for (l_i = 0;l_i < n;l_i ++){
            if (mid_queue[l_i] == pre_queue[0]){
                break;
            }
            l_mid_queue[l_i] = mid_queue[l_i];
        }
        for (int r_i = l_i + 1;r_i < n;r_i ++){
            r_mid_queue[r_i - l_i - 1] = mid_queue[r_i];
        }
        int l_pre_queue[n];
        int r_pre_queue[n];
        for (int l_j = 1;l_j <= l_i;l_j ++){
            l_pre_queue[l_j - 1] = pre_queue[l_j];
        }
        for (int r_j = l_i + 1;r_j < n;r_j ++){
            r_pre_queue[r_j - l_i - 1] = pre_queue[r_j];
        }
        root -> rchild = TreeBuild(r_pre_queue, r_mid_queue, n - 1 - l_i);
        root -> lchild = TreeBuild(l_pre_queue, l_mid_queue, l_i);
        return root;
    }
}

void Print(struct Node *node){
    if (node == NULL){
        return;
    }
    Print(node -> lchild);
    Print(node -> rchild);
    cout << node -> key << ' ';
    return;
}


int main(){
    int n;
    cin >> n;
    int pre_queue[n], mid_queue[n];
    for (int i = 0;i < n;i ++){
        cin >> pre_queue[i];
    }
    for (int i = 0;i < n;i ++){
        cin >> mid_queue[i];
    }

    struct Node *root = TreeBuild(pre_queue, mid_queue, n);
    Print(root -> lchild);
    Print(root -> rchild);
    cout << root -> key;
    return 0;
}