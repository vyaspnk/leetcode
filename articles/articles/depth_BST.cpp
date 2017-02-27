//
//  depth_BST.cpp
//  articles
//
//  Created by Vijetha Malla on 2/23/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include <iostream>
#include <stack>
#include "BinaryTree.hpp"
using namespace std;
int
Solution::BSTDepth_iterative(TreeNode *root) {
    if (!root) return 0;
    auto curr = root;
    stack<TreeNode*> s;
    stack<int> l;
    int maxDepth = 0;
    int level = 0;
    while(1) {
    	while(curr) {
            level++;
            if(curr->right) {
                cout << "pushing " << curr->right->val << "-" << level+1 << endl;
                s.push(curr->right);
                l.push(level+1);
                if(maxDepth < level+1) maxDepth = level+1 ;
            }
            cout << curr->val << " ";
            curr = curr->left;
        }
        if(s.empty())
            return maxDepth;
        curr = s.top();
        s.pop();
	}
    return maxDepth;
}
