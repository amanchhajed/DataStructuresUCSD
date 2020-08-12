#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;

class Tree {
  public:
    int data;
    Tree* left, *right;
    Tree(): data(0), left(nullptr), right(nullptr){}
};

class TreeOrders {
  int n;
  vector<Tree*> nodes;

public:
  void read() {
    cin >> n;
    nodes.resize(n);
    for(int i=0;i<n;i++) {
      nodes[i] = new Tree{};
    }
    int key, left, right;
    for (int i = 0; i < n; i++) {
      cin >> key >> left >> right;
      nodes[i]->data = key;
      if(left!=-1)
        nodes[i]->left = nodes[left];
      if(right!=-1)
        nodes[i]->right = nodes[right];
    }
  }


  vector <int> in_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    in_order_(result, nodes[0]);
    return result;
  }
  void in_order_(vector<int>& result, Tree* node) {
    if(node) {
      in_order_(result, node->left);
      result.push_back(node->data);
      in_order_(result, node->right);
    }
  }

  vector <int> pre_order() {
    vector<int> result;    
    // Finish the implementation
    // You may need to add a new recursive method to do that
    pre_order_(result, nodes[0]);
    return result;
  }
  void pre_order_(vector<int>& result, Tree* node) {
    if(node) {
      result.push_back(node->data);
      pre_order_(result, node->left);
      pre_order_(result, node->right);
    }
  }

  vector <int> post_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    post_order_(result, nodes[0]);
    return result;
  }
  void post_order_(vector<int>& result, Tree* node) {
    if(node) {
      post_order_(result, node->left);
      post_order_(result, node->right);
      result.push_back(node->data);
    }
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}

