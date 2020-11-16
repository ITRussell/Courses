/*
Given a binary tree, populate an array to represent its level-by-level traversal. 
You should populate the values of all nodes of each level from left to right in separate sub-arrays.
*/

using namespace std;

#include<vector>
#include<queue>
#include<iostream>

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

class Operations{
public:
    static vector<vector<int>> traverse(TreeNode* root){
       vector<vector<int>> result;
       if (root == nullptr){
           return result;
       }     
       queue<TreeNode*> q;
       q.push(root);
       while (!q.empty()){
           int levelSize = q.size();
           vector<int> currLevel;
           for (int i = 0; i < levelSize; i++){
               TreeNode* currNode = q.front();
               q.pop();
               currLevel.push_back(currNode->key);
               if (currNode->left != nullptr){
                   q.push(currNode->left);
               }
               if (currNode->right != nullptr){
                   q.push(currNode->right);
               }
           }
           result.push_back(currLevel);
       }
       return result;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);


    vector<vector<int>> res = Operations::traverse(root);

    for (auto level : res){
        for (auto val : level){
            cout << val << " ";
        }
        cout << "\n";
    }
}