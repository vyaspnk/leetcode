//
//  BSTtoFile.cpp
//  articles
//
//  Created by Vyas on 2/25/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
#include "istringstream"
#include "BinaryTree.hpp"
using namespace std;


string Solution::BSTtoFile(TreeNode* root) {
    string result = "[";
    if(!root)
        return result+"]";
    auto curr = root;
    stack<TreeNode*> s;
    while(1){
        while(curr) {
            result+=curr->val;
            result+=",";
            cout << result << endl;
            if(curr->right)
                s.push(curr->right);
            curr = curr->left;
        }
    	if(!s.empty()) {
            curr = s.top();
        	s.pop();
        } else {
            break;
        }
	}
    return result+"]";
}

TreeNode *
Solution::DeserializeBST(string S) {
    TreeNode *root;
    istringstream in(S);
    int val;
    int c = 0;
    int n = 1;
    stack<char> st;
    for(i = 0; i< S.size(); i++) {
        if(S[c] > s[i]){
            in >> val;
            if(in >> val) {
                cout << "Invalid string:"<< endl;
                return nullptr;
            }
            
    		root = new TreeNode(val);
        }
    }
}
