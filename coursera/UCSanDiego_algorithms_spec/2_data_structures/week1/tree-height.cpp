#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using namespace std;

class Node;

class Node {
public:
    int key;
    int height;
    Node *parent;
    vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};


int main_with_large_stack_space() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;

    vector<Node> nodes(n);
    Node *root;

    for (int child_index = 0; child_index < n; child_index++) {
        int parent_index;
        cin >> parent_index;

        nodes[child_index].key = child_index;

        if (parent_index >= 0) {
            nodes[child_index].setParent(&nodes[parent_index]);
        } else if (parent_index == -1) {
            root = &nodes[child_index];
        }
    }

    queue<Node*> next_nodes;
    next_nodes.push(root);

    root->height = 1;
    int maxHeight = 0;

    while (!next_nodes.empty()) {
      Node* n = next_nodes.front();
      int h = n->height;

      for(int i = 0; i < n->children.size(); ++i){
          n->children[i]->height = h + 1;
          next_nodes.push(n->children[i]);
      }

      next_nodes.pop();
      maxHeight = h;
    }

    cout << maxHeight << std::endl;
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
