//
//  BTree_next_right.cpp
//  articles
//
//  Created by Vyas on 2/23/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include <iostream>
#include "BinaryTree.hpp"
using namespace std;

void
Solution::SetNextRight(TreeNode *root) {
    if(!root )//|| (!root->left && !root->right))
        return;
    TreeNode *rightsibling = root->right;
//    auto t = (root->nextright)?root->nextright->val:0;
//    cout << "Node "<< root->val << " --> " << t << endl;
//    if(root->left)
//        root->left->nextright = rightsibling;
    auto rootsibling = root->nextright;
    TreeNode *sibling = nullptr;
    if(!rootsibling) {
        sibling = nullptr;
    }
    while(rootsibling) {
        if(rootsibling->left) {
            sibling = rootsibling->left;
            break;
        }
        else if(rootsibling->right) {
            sibling = rootsibling->left;
            break;
        }
        else
            rootsibling = rootsibling->nextright;
    }
    if(root->right) {
        root->right->nextright = sibling;
        if(root->left)
            root->left->nextright = root->right;
    } else if(root->left) {
        root->left->nextright = sibling;
    }
    
    SetNextRight(root->left);
    SetNextRight(root->right);
        
}

