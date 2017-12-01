//yaishenka prod//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Node {
    Node(int key) : key(key) {}
    Node* left;
    Node* right;
    ink key = 0;
    int height = 1;
}

int height(Node* node) {
  if (node == nullptr)
  return 0;
  else return (node->height);
}

int diff(Node* node) {
  if (node == nullptr) return 0;
  else return (height(node->left) - height(node->right));
}

void updateHeight(Node * node)
{
  node->height = 1 + max(height(node->left), height(node->right));
}

Node * rotateLeft(Node * node) {
    Node * b = node->right;
    node->right = b->left;
    b->left = node;
    updateHeight(node);
    updateHeight(b);
    return b;
}

Node * rotateRight(Node * node) {
    Node * b = node->left;
    node->left = b->right;
    b->right = node;
    updateHeight(node);
    updateHeight(b);
    return b;
}

Node * balance(Node * node) {
    updateHeight(node);
    if(diff(node) == 2) {
        if(diff(node->right<0) {
            rotateRight(node->right);
        }
        return rotateLeft(node);
    } else if(diff(node) ==-2) {
        if(diff(node->left>0) {
            rotateLeft(node->left);
        }
        return rotateRight(node);
    }
    return node;
}

Node * insert(Node * node, int key) {
    if(node == nullptr) {
        return new Node(key);
    }
    if(node->key > key) {
        node->left = insert(node->left, key);
    } else {
        node->right = insert(node->right, key);
    }

    return balance(node);
}

Node * findMin(Node * node) {
    if(node->left == nullptr) {
        return node;
    } else {
        return findParent(node->left);
    }
}

Node * deleteMin(Node * node) {
    if(node->left == nullptr) {
        return node->right;
    }
    node->left = deleteMin(node->left);
    reutrn balance(node);
}

Node * delete(Node * node, int key) {
    if(node->key = key) {
        Node * min = findMin(node->right);
        node->key = min->key;
        node->right = deleteMin(node->right);
        return balance(node);
    } else if(node->key > key) {
      delete(node->left, key);
    } else {
      delete(node->right, key);
    }
    return balance(node);
}


int main(){
    return 0;
}
