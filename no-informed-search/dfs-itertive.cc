#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
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

void DFS(const Node &initialNode, const Node &solutionNode) {
  stack<Node> frontierNodes;
  set<string> visitedNodes;

  frontierNodes.push(initialNode);

  while (!frontierNodes.empty()) {
    Node currentNode = frontierNodes.top();
    frontierNodes.pop();

    string currentNodeStr = nodeToString(currentNode);
    if (visitedNodes.count(currentNodeStr))
      continue;

    for (int n : currentNode)
      cout << n << " ";
    cout << endl;

    if (currentNode == solutionNode) {
      cout << "Solution found" << endl;
      return;
    }

    visitedNodes.insert(currentNodeStr);

    vector<Node> children = generateChildren(currentNode);
    for (Node &childNode : children) {
      string childStr = nodeToString(childNode);
      if (!visitedNodes.count(childStr)) {
        frontierNodes.push(childNode);
      }
    }
  }
}

int main() {
  Node initialNode = {4, 2, 3, 1};
  Node solutionNode = {1, 2, 3, 4};

  cout << "DFS Iterative [4,2,3,1]...\n";
  DFS(initialNode, solutionNode);

  return 0;
}
