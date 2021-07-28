/*
Given a binary tree and a number ‘S’, find all paths in the tree such that the sum of all the node values of each path equals ‘S’. 
Please note that the paths can start or end at any node but all paths must follow direction from parent to child (top to bottom). 
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class CountAllPathSum {
 public:
  static int countPaths(TreeNode *root, int S) {
      vector<int> currPath;
      return findPathRecursive(root, S, currPath);
  }
private:
    static int findPathRecursive(TreeNode* currNode, int sum, vector<int> &currPath){
        if (currNode == nullptr){
            return 0;
        }
        currPath.push_back(currNode->val);
        int pathSum = 0, pathCount = 0;
        for (vector<int>::reverse_iterator itr = currPath.rbegin(); itr != currPath.rend(); ++itr){
            pathSum += *itr;
            if (pathSum == sum){
                pathCount++;
            }
        }
        pathCount += findPathRecursive(currNode->left, sum, currPath);
        pathCount += findPathRecursive(currNode->right, sum, currPath);
        currPath.pop_back();
        return pathCount;
    }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree has path: " << CountAllPathSum::countPaths(root, 11) << endl;
}
