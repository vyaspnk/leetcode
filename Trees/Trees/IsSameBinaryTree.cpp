//
//  IsSameBinaryTree.cpp
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
using namespace std;


bool
Solution::IsSameTree(TreeNode * p, TreeNode *q) {
    if(p == q)
        return true;
    if((!p && q) || (p && !q))
        return false;
    TreeNode *cp = p;
    TreeNode *cq = q;
    if(cp && cq) {
        if(cp->val != cq->val)
            return false;
        if(!IsSameTree(cp->left, cq->left)) return false;
        if(!IsSameTree(cp->right, cq->right)) return false;
    }
    return true;
}

