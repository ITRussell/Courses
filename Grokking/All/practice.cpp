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

        bool foward = true;
        while(!q.empty()){
            int levelSize = q.size();
            vector<int> currLevel(levelSize);
            for (int i = 0; i < levelSize; i++){
                TreeNode* currNode = q.front();
                q.pop();

                if (foward){
                    currLevel[i] = currNode->key;
                }
                else {
                    currLevel[levelSize-1 - i] = currNode->key;
                }

                if (currNode->left != nullptr){
                    q.push(currNode->left);
                }
                if (currNode->right != nullptr){
                    q.push(currNode->right);
                }
            }
            result.push_back(currLevel);
            foward = !foward;
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
    cout << "\n";
  }
}
