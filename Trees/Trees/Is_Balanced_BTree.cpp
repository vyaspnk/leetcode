//
//  Is_Balanced_BTree.cpp
//  Trees
//
//  Created by Vyas on 2/18/17.
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

bool
Solution::isBalanced(TreeNode* root) {
    if(!root)
        return true;
    int left = depth(root->left);
    int right = depth(root->right);
    
    return (abs(left-right)<=1)&& isBalanced(root->left)&&isBalanced(root->right);
}
