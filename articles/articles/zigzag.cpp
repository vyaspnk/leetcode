//
//  zigzag.cpp
//  articles
//
//  Created by Vijetha Malla on 2/24/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include <stdio.h>


#include <iostream>
#include "BinaryTree.hpp"
#include <stack>
#include <queue>
#include <vector>
using namespace std;

#define COUNT(level,q,s)    ((level%2==0)?q.size():s.size())
#define POP(level,q,s)      ((level%2==0)?q.pop():s.pop())
#define PUSH(level,q,s,c)     ((level%2==0)?q.push(c):s.push(c))
#define TOP(level,q,s)      ((level%2==0)?q.top():s.top())

static void
printstackqueue(stack<TreeNode*> s, stack<TreeNode*> q) {
    cout << "s: ";
    while(!s.empty()) {
        cout << s.top()->val << " ";
        s.pop();
    }
    cout << endl;
    cout << "q: ";
    while(!q.empty()) {
        cout << q.top()->val << " ";
        q.pop();
    }
    cout << endl;
    
}
vector<vector<int>>
Solution::zigzag(TreeNode* root) {

    vector<vector<int>> result;
    if(!root)
    return result;
    auto level = 0;
    stack<TreeNode *> q;
    stack<TreeNode *> s;
    PUSH(level,q,s,root);
    while(COUNT(level,q,s)) {
        result.push_back(vector<int>());
        auto nodecount = COUNT(level,q,s);
        while(nodecount){
            auto curr = TOP(level,q,s);
            nodecount--;
            result[level].push_back(curr->val);
            POP(level,q,s);
            if((level+1)%2!=0) {
                if(curr->left)
                    PUSH((level+1),q,s,curr->left);
                if(curr->right)
                    PUSH((level+1),q,s,curr->right);
            } else {
                if(curr->right)
                    PUSH((level+1),q,s,curr->right);
                if(curr->left)
                    PUSH((level+1),q,s,curr->left);
            }
        }
        //cout<<endl;
        level++;
        cout << "level " << level << endl;
        printstackqueue(s,q);
    }
    return result;
	
}
