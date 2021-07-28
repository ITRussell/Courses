/*
Given a binary tree where each node can only have a digit (0-9) value, each root-to-leaf path will represent a number. 
Find the total sum of all the numbers represented by all paths.
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

class SumOfPathNumbers {
public:
    static int findSumOfPathNumbers(TreeNode* root){
        int pathDigit = 0;
        int totalSum = 0;
        findPathRecursive(root, pathDigit, totalSum);
        return totalSum;
    }

private:
    static int findPathRecursive(TreeNode* currNode, int &pathDigit, int &totalSum){
        if (currNode == nullptr){
            return 0;
        }
        pathDigit = appendDigit(pathDigit, currNode->val);
        if (currNode->left == nullptr && currNode->right == nullptr){
            return pathDigit;
        }
      
        return findPathRecursive(currNode->left, pathDigit, totalSum) +
            findPathRecursive(currNode->right, pathDigit, totalSum);
        
    }

    static int appendDigit(int currDigit, int nextDigit){
        int newDigit = currDigit*10 + nextDigit;
        return newDigit;
    }
    
    static int removeDigit(int currDigit){
        int newDigit = currDigit / 10;
        return newDigit;
    }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);
  cout << "Total Sum of Path Numbers: " << SumOfPathNumbers::findSumOfPathNumbers(root) << "\n";
}