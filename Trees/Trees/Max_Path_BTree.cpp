//
//  Max_Path_BTree.cpp
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
#include <unordered_map>
using namespace std;

int Solution::maxPathSum(TreeNode *root) {
    if (!root) return 0;
    return root->val + max(maxPathSum(root->left), maxPathSum(root->right));
}
