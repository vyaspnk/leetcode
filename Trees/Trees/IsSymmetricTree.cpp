//
//  IsSymmetricTree.cpp
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

void
swap(deque<TreeNode*> * &checknodes,deque<TreeNode*> * &addnodes) {
    deque<TreeNode*> * tmp = checknodes;
    checknodes = addnodes;
    addnodes = tmp;
    }
bool
Solution::IsSymmetricTree(TreeNode * root) {
    if(!root) return true;
    auto c = root;
    if((c->left && !c->right) || (!c->left && c->right)) return false;
    deque<TreeNode*> QA, QB;
    auto &checknodes = QA, &addnodes = QB;
    checknodes.push_back(c->left);
    checknodes.push_front(c->right);
    while(checknodes.size()){
        auto nodecount = (int)checknodes.size();
        auto qb = checknodes.begin();
        auto qe = checknodes.rbegin();
    	for(; nodecount > 0 && qb!=checknodes.end() && qe!= checknodes.rend();
            qb++, qe++,nodecount = nodecount-2) {
            auto l = *qb, r = *qe;
            if(!l && !r) continue;
            if((l && !r) || (!l && r) || (l->val != r->val)) return false;
            addnodes.push_back(l->right);
            addnodes.push_back(l->left);
            addnodes.push_front(r->left);
            addnodes.push_front(r->right);
        }
        checknodes.clear();
        swap(checknodes,addnodes);
    }
    return true;
}
