
#include <iostream>
#include <vector>
#include "unordered_map"
using namespace std;

//maximum sum between any two nodes in BTREE;
//keep track of the maximum sum so far but recursion should only return
//the max sum of the subtree ( max(leftsum,rightsum)+root->val)

/**
 Definition for a binary tree node.
 */ struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class MAXPATHSUM {
private:
    int maxPathDown(TreeNode *root, int &max) {
        if(!root) return 0;
        auto left = std::max(0,maxPathDown(root->left,max));
        auto right = std::max(0,maxPathDown(root->right,max));
        max = std::max(max, left+right+root->val);
        return std::max(left,right) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int max = INT_MIN;
        maxPathDown(root,max);
        return max;
    }
};
