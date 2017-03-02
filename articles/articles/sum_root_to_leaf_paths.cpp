//
//  sum_root_to_leaf_paths.cpp
//  articles
//
//  Created by Vyas on 2/27/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
#include "unordered_map"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//void getPaths(TreeNode * root, vector<int> &S) {
//    if(!root) return;
//    if(!root->left && !root->right) return;
//    getPaths(root->left, S);
//    getPaths(root->right, S);
//}

int sumNumbers(TreeNode* root) {
    queue<pair<TreeNode*,int>> Q;
    if(!root)
        return 0;
    auto SUM = 0;
    Q.push(make_pair(root,0));
    while(Q.size()) {
        auto nodecount = Q.size();
        while(nodecount) {
            nodecount--;
            auto q = Q.front().first;
            auto v = Q.front().second;
            Q.pop();
            if(!q->left && !q->right)  SUM+=(v*10)+q->val;
            else
            {
                if(q->left)
                    Q.push(make_pair(q->left, (v*10)+q->val));
                if(q->right)
                    Q.push(make_pair(q->right,(v*10)+q->val));
            }
        }
    }
    return SUM;
}
