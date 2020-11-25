/*
Given a binary tree and a number ‘S’, find all paths from root-to-leaf such that the
 sum of all the node values of each path equals ‘S’.
 */

#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int val = 0;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int k){
        this->val = k;
        left = right = nullptr;
    }
 };

class FindAllTreePaths {
public:
    static vector<vector<int>> findPaths(TreeNode* root, int sum){
        vector<vector<int>> allPaths;
        vector<int> currentPath;
        findPathRecursive(root, sum, currentPath, allPaths);
        return allPaths;
    }

private:
    static void findPathRecursive(TreeNode* currNode, int sum, vector<int> &currentPath, vector<vector<int>> &allPaths){
        if (currNode == nullptr){
            return;
        }
        currentPath.push_back(currNode->val);
        if (sum == currNode->val && currNode->left == nullptr && currNode->right == nullptr){
            allPaths.push_back(currentPath);
        }
        else {
            findPathRecursive(currNode->left, sum - currNode->val, currentPath, allPaths);
            findPathRecursive(currNode->right, sum - currNode->val, currentPath, allPaths);
        }
        currentPath.pop_back();
    }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  int sum = 23;
  vector<vector<int>> result = FindAllTreePaths::findPaths(root, sum);
  cout << "Tree paths with sum " << sum << ": " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
