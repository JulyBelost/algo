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

void in_order_process(const vector<Node>& tree, vector<long long> & res, int i) {
    int delta = 0;

    if(tree[i].left != -1) {
        if(tree[tree[i].left].key == tree[i].key){
            ++delta;
        }
        in_order_process(tree, res, tree[i].left);
    }

    res.push_back(tree[i].key - delta);


    if(tree[i].right != -1) {
        in_order_process(tree, res, tree[i].right);
    }
}

bool IsBinarySearchTree(const vector<Node>& tree) {
    if(tree.empty()) {
        return true;
    }

    vector<long long> result;
    in_order_process(tree, result, 0);

    for (int i = 0; i < result.size() - 1; ++i) {
        if(result[i] > result[i + 1]) {
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
