//
//  Is_BST.cpp
//  articles
//
//  Created by Vijetha Malla on 2/24/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include <iostream>
#include "BinaryTree.hpp"
#include <stack>
using namespace std;


bool
isBST(TreeNode* p, int &prev) {
    if (!p) return true;
    if (isBST(p->left, prev)) {
        if (p->val > prev) {
            prev = p->val;
            return isBST(p->right, prev);
        } else {
            return false;
        }
    }
    else {
        return false;
    }
}
