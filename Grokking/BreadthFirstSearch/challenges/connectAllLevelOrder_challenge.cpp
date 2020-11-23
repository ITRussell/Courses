/*
Given a binary tree, connect each node with its level order successor. The last node of each level
should point to the first node of the next level.
*/

#include <iostream>
#include <queue>
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

    virtual void printLevelOrder(){
        TreeNode* currNode = this;
        while (currNode != nullptr){
            cout << currNode->val << " ";
            currNode = currNode->next;
        }
    }
};

class Operations {
public:
    static void connect(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* currNode;
        while (!q.empty()){

            currNode = q.front();
            if (currNode != nullptr){
                cout << currNode->val << " ";

            }
            q.pop();

            if (currNode != nullptr){
                currNode->next = q.front();
                cout << currNode->next->val << " ";
            }
        
            if (currNode->left != nullptr){
                q.push(currNode->left);
            }
            if (currNode->right != nullptr){
                q.push(currNode->right);
            }
            
        }
    }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  Operations::connect(root);
  //root->printLevelOrder();
}