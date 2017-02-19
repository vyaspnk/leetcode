//
//  Mode_in_Binary_Tree.cpp
//  Trees
//
//  Created by Vijetha Malla on 2/18/17.
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

/**
 * Traverse the tree using depth first search.
 * Return the mode count (i.e. The count of a repeated number that occurs the most.) of the tree.
 */
int getModeCount(TreeNode* root, unordered_map<int, int> &map) {
    if(root == NULL)
        return 0;
    
    if(map.find(root->val) == map.end()) {
        map.insert(pair<int, int>(root->val, 1));
    }
    else {
        map[root->val]++;
    }
    
    return max(map[root->val], max(getModeCount(root->left, map), getModeCount(root->right, map)));
}
int getModeCount_NonRec(TreeNode *root, unordered_map<int,int> &map) {
    if(!root)
        return 0;
    auto max = 1;
    queue<TreeNode *> Q;
    Q.push(root);
    while(Q.size()) {
        auto nodecount = Q.size();
        while (nodecount--) {
            auto c = Q.front();
            Q.pop();
            if(map.find(c->val)==map.end())
                map.insert(pair<int,int>(c->val, 1));
            else {
                map[c->val]++;
                if(max<map[c->val])
                    max = map[c->val];
            }
            if(c->left)
                Q.push(c->left);
            if(c->right)
                Q.push(c->right);
        }
    }
    return max;
}

vector<int>
Solution::findMode(TreeNode* root) {
    unordered_map<int, int> map;
    vector<int> result;
    int modeCount = getModeCount_NonRec(root, map);
    
    for(pair<int,int> p : map) {
        if(p.second == modeCount) {
            result.push_back(p.first);
        }
    }
    
    return result;
    
}

