//
//  Invert_A_BST.cpp
//  Trees
//
//  Created by Vyas on 2/17/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include "BinaryTree.h"

#include <iostream>
#include "stdlib.h"
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


TreeNode *
Solution::invertTree(TreeNode * root) {
    if(!root)
        return root;
    stack<TreeNode*> stk;
    stk.push(root);
    while(!stk.empty()){
        auto p = stk.top();
        stk.pop();
        if(p) {
            stk.push(p->left);
            stk.push(p->right);
            std::swap(p->left, p->right);
        }
    }
    return root;
}
