//
//  Min_Max_depth_Binary_Tree.cpp
//  Trees
//
//  Created by Vijetha Malla on 2/17/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include "BinaryTree.h"

#include <iostream>
#include "stdlib.h"
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

//void
//swap(deque<TreeNode*> * &a,deque<TreeNode*> * &b) { auto tmp = a; a = b; a = tmp; }

int Solution::minDepth(TreeNode* root) {
    if(!root) return 0;
    if(!root->left && !root->right) return  1;
    int minDepth = 0;
    queue<TreeNode*> Q;
    Q.push(root);
    while(Q.size()){
        auto nodecount = Q.size();
        while(nodecount--){
            auto p = Q.front();
            Q.pop();
            if(p!=root && (!p->left && !p->right) )
                return minDepth;
            if(p->left)
            	Q.push(p->left);
            if(p->right)
                Q.push(p->right);
        }
        minDepth++;
    }
    return minDepth;
}

int Solution::maxDepth(TreeNode * root) {
    if(!root) return 0;
    if(!root->left && !root->right) return  1;
    int maxDepth = 0;
    queue<TreeNode*> Q;
    Q.push(root);
    while(Q.size()){
        auto nodecount = Q.size();
        while(nodecount--){
            auto p = Q.front();
            Q.pop();
            if(p->left)
                Q.push(p->left);
            if(p->right)
                Q.push(p->right);
        }
        maxDepth++;
    }
    return maxDepth;
}
