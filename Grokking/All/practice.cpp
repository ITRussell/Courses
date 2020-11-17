/*
Given a binary tree, populate an array to represent the averages of all of its levels.
*/

#include<iostream>
#include<vector>
#include<queue>
#include<deque>
using namespace std;

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
    static vector<vector<int>> zigZag(TreeNode* root){
        vector<vector<int>> result;
        if (root == nullptr){
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            // finish zizag
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
root->right->left->left = new TreeNode(20);
root->right->left->right = new TreeNode(17);

vector<vector<int>> result = Operations::zigZag(root);
 for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
  }
}
