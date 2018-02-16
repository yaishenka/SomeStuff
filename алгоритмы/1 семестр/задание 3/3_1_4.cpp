
#include <iostream>
#include <algorithm>
using namespace std ;
struct Node {
    int key;
    Node* left=nullptr;
    Node* right=nullptr;
    Node (int k) {
        key=k;
    }
    void insert (int k) {
        if (k>=key) {
            if (right==nullptr) {
                right= new Node(k);
            } else right->insert(k);
        } else {
            if (left==nullptr) {
                left= new Node(k);
            } else left->insert(k);
        }
    }
    void debAg (){
        if (left!=nullptr) left->debAg();
        if (right!=nullptr) right->debAg();
        cout<<key<<" ";
        
    }
    void level_order (int n) {
        Node* arr[n];
        int i(0);
        int j(1);
        arr[0]=this;
        while (i<n) {
            if (arr[i]->left!=nullptr) {
                arr[j++]=arr[i]->left;
            }
            if (arr[i]->right!=nullptr) {
                arr[j++]=arr[i]->right;
            }
            cout<<arr[i++]->key<<" ";
        }
    }
};
int main () {
    int n, a;
    cin>>n;
    cin>>a;
    Node root(a);
    for (int i(1);i<n;++i) {
        cin>>a;
        root.insert(a);
    }
    root.level_order(n);
}














