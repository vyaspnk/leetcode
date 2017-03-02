/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "BinaryTree.hpp"
#include <iostream>
using namespace std;
class AMD {
private:
    void buildInOrder(TreeNode *root, vector<int> &order) {
        if(!root)
            return;
        if(root->left)
            buildInOrder(root->left,order);
        order.push_back(root->val);
        if(root->right)
            buildInOrder(root->right,order);
        return;
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> order;
        buildInOrder(root, order);
        int adiff = INT_MAX;
        for(auto i = 0;i < order.size()-1; i++) {
//            cout << order[i] << " ";
            auto delta = abs(order[i]-order[i+1]);
            if(delta < adiff)
                adiff = delta;
        }
        return adiff;
    }
};
