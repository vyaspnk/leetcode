//
//  IsSameBinaryTree.hpp
//  Trees
//
//  Created by Vijetha Malla on 2/17/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};
class Solution {
private:
    TreeNode *root;
    TreeNode *broot;
public:
    Solution () {
        root = NULL;
        broot = NULL;
    }
    void addToBTree(int val);
    TreeNode *getBTreeRoot();
    TreeNode *searchForNode(TreeNode* root,int val);
    bool IsSymmetricTree(TreeNode* root);
    bool IsSameTree(TreeNode*, TreeNode*);
    TreeNode *invertTree(TreeNode*);
    int minDepth(TreeNode* root);
    int maxDepth(TreeNode* root);
    void printInOrderTraversal(TreeNode*);
    vector<int> InOrderTraversal(TreeNode*);
    TreeNode * sortedArrayToBST(vector<int>& nums);
    int closestValue(TreeNode* root, double target);
    bool isBalanced(TreeNode* root);
    int depth(TreeNode*root);
    vector<int> findMode(TreeNode* root);
    TreeNode *LCA(TreeNode*,TreeNode*,TreeNode*);
    int maxPathSum(TreeNode *root);
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p);

};
#endif /* BinaryTree_h */
