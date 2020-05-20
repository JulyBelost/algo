#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  long long key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(long long key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

void in_order_process(const vector<Node>& tree, long long & prev, int i) {
    long long inf = INT32_MAX + (long long)1;

    if(tree[i].left != -1) {
        if(tree[tree[i].left].key == tree[i].key){
            prev = inf;
        }
        in_order_process(tree, prev, tree[i].left);
    }

    prev = prev <= tree[i].key ? tree[i].key: inf;


    if(tree[i].right != -1) {
        in_order_process(tree, prev, tree[i].right);
    }
}

bool IsBinarySearchTree(const vector<Node>& tree) {
    if(tree.size() <= 1) {
        return true;
    }

    long long prev;
    in_order_process(tree, prev = INT32_MIN, 0);

    return prev <= INT32_MAX;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    long long key;
    int left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
