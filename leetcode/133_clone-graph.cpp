// https://leetcode.com/problems/clone-graph/
// Created by Julia on 2019-08-04.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

Node* cloneNode(Node* node, map<Node*, Node*>& visited){
    if(visited.count(node)){
        return visited[node];
    }
    Node* cloned = new Node();
    cloned->val = node->val;
    visited.insert(make_pair(node, cloned));
    for(int i = 0; i < node->neighbors.size(); ++i){
        cloned->neighbors.push_back(cloneNode(node->neighbors[i], visited));
    }
    return cloned;
}

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> visited;
        return cloneNode(node, visited);
    }
};