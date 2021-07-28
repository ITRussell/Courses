/*
Given a binary tree, find the length of its diameter. The diameter of a tree is the number of nodes on 
the longest path between any two leaf nodes. The diameter of a tree may or may not pass through the root.
Note: You can always assume that there are at least two leaf nodes in the given tree.
*/

#include<iostream>
#include<vector>

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


class TreeDiameter {
 public:
  static int findDiameter(TreeNode *root) {
    int treeDiameter = 0;
    calculateHeight(root, treeDiameter);
    return treeDiameter;
  }

  static int calculateHeight(TreeNode* currNode, int &treeDiameter) {

  	if (currNode == nullptr){
  		return 0;
  	}

  	int leftTreeHeight = calculateHeight(currNode->left, treeDiameter);
  	int rightTreeHeight = calculateHeight(currNode->right, treeDiameter);
	
  	int currDiameter = leftTreeHeight + rightTreeHeight + 1;
  	treeDiameter = max(currDiameter, treeDiameter);
  	return max(leftTreeHeight, rightTreeHeight) + 1;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);
  cout << "Tree Diameter: " << TreeDiameter::findDiameter(root) << endl;
  root->left->left = nullptr;
  root->right->left->left = new TreeNode(7);
  root->right->left->right = new TreeNode(8);
  root->right->right->left = new TreeNode(9);
  root->right->left->right->left = new TreeNode(10);
  root->right->right->left->left = new TreeNode(11);
  cout << "Tree Diameter: " << TreeDiameter::findDiameter(root) << endl;
}