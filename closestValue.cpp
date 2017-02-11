/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int result=root->val;
        while(root){
            if(abs((double)root->val-target)<abs(result-target))
                result=root->val;
            if(root->val>target)root=root->left;
            else root=root->right;
        }
        return result;
    }
};