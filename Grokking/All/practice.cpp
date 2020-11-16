/*
Given a binary tree, populate an array to represent the averages of all of its levels.
*/

using namespace std;
#include<iostream>
#include<vector>
#include<queue>
#include<deque>

class TreeNode {
public:
    int key = 0;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int k){
        this->key = k;
        left = right = nullptr;
    }
};

class Operations {
public:
   
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  deque<vector<int>> result;
  cout << "Level order traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
