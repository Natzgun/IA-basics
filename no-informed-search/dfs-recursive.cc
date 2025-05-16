#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef vector<int> Node;

string nodeToString(const Node &node) {
  string s;
  for (int n : node)
    s += to_string(n);
  return s;
}

vector<Node> generateChildren(const Node &currentNode) {
  vector<Node> children;

  Node left = currentNode;
  swap(left[0], left[1]);
  children.push_back(left);

  Node center = currentNode;
  swap(center[1], center[2]);
  children.push_back(center);

  Node right = currentNode;
  swap(right[2], right[3]);
  children.push_back(right);

  return children;
}

bool DFS_rec(const Node &node, const Node &solution, set<string> &visited) {
  string node_str = nodeToString(node);
  visited.insert(node_str);

  for (int n : node)
    cout << n << " ";
  cout << endl;

  if (node == solution) {
    cout << "Founded" << endl;
    return true;
  }

  vector<Node> children = generateChildren(node);
  for (const Node &node_hijo : children) {
    string child_str = nodeToString(node_hijo);
    if (!visited.count(child_str)) {
      bool s = DFS_rec(node_hijo, solution, visited);
      if (s)
        return true;
    }
  }

  return false;
}

int main() {
  Node initialNode = {4, 2, 3, 1};
  Node solutionNode = {1, 2, 3, 4};

  set<string> visited;

  cout << "DFS Recursive [4,2,3,1]...\n";
  DFS_rec(initialNode, solutionNode, visited);

  return 0;
}
