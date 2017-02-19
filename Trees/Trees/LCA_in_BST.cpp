//
//  LCA_in_BST.cpp
//  Trees
//
//  Created by Vijetha Malla on 2/18/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include "BinaryTree.h"

#include <iostream>
#include "stdlib.h"
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

//!(root->val>lhs->val && root->val < rhs->val)) {


TreeNode *
Solution::LCA(TreeNode * root, TreeNode * p , TreeNode * q) {
    TreeNode *lhs = (p->val<=q->val)?p:q;
    TreeNode *rhs = (p->val>=q->val)?p:q;
    while(1) {
        if(root->val >= lhs->val && root->val <= rhs->val)
            return root;
        else if(root->val < lhs->val)
            root = root->right;
        else if(root->val > rhs->val)
            root = root->left;
        
    }
    
        return root;
   }
