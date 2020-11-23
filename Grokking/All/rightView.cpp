/*
Given a binary tree, return an array containing nodes in its right view. 
The right view of a binary tree is the set of nodes visible when the tree is seen from the right side.
*/

#include <queue>
#include <iostream>
using namespace std;

class TreeNode {
public:
    int val = 0;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;
    TreeNode(int k){
        this->val = k;
        left = right = next = nullptr;
    }
};

class Operations {
public:
    static vector<TreeNode*> rightView(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> result;
        while (!q.empty()){
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++){
                TreeNode* currNode = q.front();
                if (i == levelSize-1){
                    result.push_back(currNode);
                }
                q.pop();
                if (currNode->left != nullptr){
                    q.push(currNode->left);
                }
                if (currNode->right != nullptr){
                    q.push(currNode->right);
                }
            }

               
        }
        return result;
    }
};


int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  root->left->left->right = new TreeNode(3);
  vector<TreeNode *> result = Operations::rightView(root);
  for (auto node : result) {
    cout << node->val << " ";
  }
}