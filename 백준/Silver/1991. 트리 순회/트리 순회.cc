#include <iostream>

using namespace std;

int tree[26][2];

void preorder(int root) {
    if(root == -1) {
        return;
    }
    cout << char(root);
    preorder(tree[root-65][0]);
    preorder(tree[root-65][1]);
}
void inorder(int root) {
    if(root == -1) {
        return;
    }
    inorder(tree[root-65][0]);
    cout << char(root);
    inorder(tree[root-65][1]);
}
void postorder(int root) {
    if(root == -1) {
        return;
    }
    postorder(tree[root-65][0]);
    postorder(tree[root-65][1]);
    cout << char(root);
}

int main () {
    int N;
    cin >> N;
    for (int i=0;i<N;i++) {
        char r; 
        cin >> r;
        int root = r - 65;
        for (int j=0;j<2;j++) {
            char c;
            cin >> c;
            int child;
            if(c == '.') child = -1;
            else child = int(c);
            tree[root][j] = child;
        }
    }
    preorder(65);
    cout << "\n";
    inorder(65);
    cout << "\n";
    postorder(65);
    cout << "\n";
}