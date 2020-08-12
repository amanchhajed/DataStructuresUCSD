#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  Node* left;
  Node* right;

  Node() : key(0), left(nullptr), right(nullptr) {}
};

bool IsBinarySearchTree(Node* node, int minima, int maxima) {
  // Implement correct algorithm here
  if(!node)
    return true;
  if(node->key < minima || node->key > maxima)
    return false;
  return IsBinarySearchTree(node->left, minima, node->key-1) && IsBinarySearchTree(node->right, node->key, maxima);
}

int main() {
  int nodes;
  cin >> nodes;
  if(nodes==0)
    return 0;
  vector<Node*> tree(nodes);
  for(int i=0;i<nodes;i++) {
    tree[i] = new Node{};
  }
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree[i]->key = key;
    if(left!=-1)
      tree[i]->left = tree[left];
    if(right!=-1)
      tree[i]->right = tree[right];

  }
  if (IsBinarySearchTree(tree[0], INT_MIN, INT_MAX)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
