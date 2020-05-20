#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

void in_order_process(const vector<Node>& tree, vector<int> & res, int i) {
    if(tree[i].left != -1) {
        in_order_process(tree, res, tree[i].left);
    }

    res.push_back(tree[i].key);

    if(tree[i].right != -1) {
        in_order_process(tree, res, tree[i].right);
    }
}

bool IsBinarySearchTree(const vector<Node>& tree) {
    if(tree.empty()) {
        return true;
    }

    vector<int> result;
    in_order_process(tree, result, 0);

    for (int i = 0; i < result.size() - 1; ++i) {
        if(result[i] >= result[i + 1]) {
            return false;
        }
    }

    return true;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
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
