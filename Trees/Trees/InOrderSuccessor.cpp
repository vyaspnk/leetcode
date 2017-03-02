//
//  InOrderSuccessor.cpp
//  Trees
//
//  Created by Vijetha Malla on 3/2/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include "BinaryTree.h"
using namespace std;
TreeNode* Solution::inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* r = NULL;
    while (root) {
        if(root->val > p->val) {
            r = root;
            root = root->left;
        } else root = root->right;
    }
    return r;
}
