/*
Given a binary tree and a number sequence, find if the sequence is present as a root-to-leaf path in the given tree.
*/

#include <algorithm>
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

class PathWithGivenSequence {
public:
    static bool findPath(TreeNode *root, const vector<int> &sequence) {
        return findPathRecursive(root, sequence, 0);
    }

private:
    static bool findPathRecursive(TreeNode* currNode, const vector<int> &sequence, int sequenceIndex){
        if (currNode == nullptr){
            return false;
        }
        if (currNode->val != sequence[sequenceIndex] || sequenceIndex >= sequence.size()){
            return false;
        }
        if (currNode->left == nullptr && currNode->right == nullptr && sequenceIndex == sequence.size()-1){
            return true;
        }
        return findPathRecursive(currNode->left, sequence, sequenceIndex+1) || findPathRecursive(currNode->right, sequence, sequenceIndex+1);
    }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);

  cout << "Tree has path sequence: " << PathWithGivenSequence::findPath(root, vector<int>{1, 0, 7})
       << endl;
  cout << "Tree has path sequence: " << PathWithGivenSequence::findPath(root, vector<int>{1, 1, 6})
       << endl;
}