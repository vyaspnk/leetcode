//
//  Closest_value_BST.cpp
//  Trees
//
//  Created by Vyas on 2/17/17.
//  Copyright © 2017 vyas. All rights reserved.
//
#include "BinaryTree.h"

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#define D(c) 	(double)(c->val)
#define LD(c) 	(double)(c->left->val)
#define RD(c) 	(double)(c->right->val)
#define closest(a,b,t) ((abs((a-t)) < abs((t-b)))? a:b)
TreeNode *findMin(TreeNode* root) {
    while( root->left) root = root->left;
    return root;
}
TreeNode *findMax(TreeNode* root) {
    while( root->right) root = root->right;
	return root;
}

int Solution::closestValue(TreeNode* root, double target) {
    int closest = root->val;
    while(root){
        if( abs(closest-target)>=abs(root->val - target))
            closest = root->val;
        root = (target > root->val) ? root->right : root->left;
    }
    return closest;
}
