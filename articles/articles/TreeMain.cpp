//
//  TreePrimitives.cpp
//  Trees
//
//  Created by Vyas on 2/17/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "queue"
#include <stack>
#include "BinaryTree.hpp"
using namespace std;
deque<TreeNode*> myq;
void
Solution::addToBTree(int val) {
    if(!broot) {
        myq.clear();
        broot  = new TreeNode(val);
        myq.push_back(broot);
        return;
    }
    TreeNode *curr = myq.front();
    if(!curr->left){
        curr->left = new TreeNode(val);
        myq.push_back(curr->left);
    } else if(!curr->right){
        curr->right = new TreeNode(val);
        myq.push_back(curr->right);
        myq.pop_front();
    }
    return;
}
TreeNode *
Solution::getBTreeRoot(){
    return broot;
}
void
Solution::setBTreeRoot(TreeNode *root){
    broot = root;
}
TreeNode *
Solution::searchForNode(TreeNode *root,int val){
    auto curr = root;
    while(curr && curr->val !=val) {
        if(val<curr->val)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return curr;
}
int
Solution::depth(TreeNode*root){
    if(!root)
        return 0;
    return max(depth(root->left),depth(root->right))+1;
}

vector<int>
Solution::InOrderTraversal(TreeNode* root) {
    vector<int> values;
    stack<TreeNode*> stack;
    if(!root)
        return values;
    auto curr = root;
    while(1) {
        while(curr){
            stack.push(curr);
            curr = curr->left;
        }
        if(!stack.size())
            return values;
        curr = stack.top();
        stack.pop();
        values.push_back(curr->val);
        curr = curr->right;
    }
    return values;
}
void
Solution::printInOrderTraversal(TreeNode *root) {
    if(!root)
        return;
    stack<TreeNode *> stack;
    auto curr = root;
    while(1) {
        while(curr){
            stack.push(curr);
            curr = curr->left;
        }
        
        if(!stack.size())
            break;
        curr = stack.top();
        stack.pop();
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout << endl;
}
int main(){
    vector<TreeNode> V;
//    V.push_back(TreeNode(1));
//    
//    V.push_back(2);
//    V.push_back(3);
//    
//    V.push_back(4);
//    V.push_back(5);
//    V.push_back(6);
//    V.push_back(7);
    
//    V.push_back(0);
//    V.push_back(6);
//    V.push_back(7);
//    V.push_back(8);
//    V.push_back(8);
//    V.push_back(7);
//    V.push_back(6);
//    V.push_back(0);
    
    Solution s;
//    for(auto it:V) {
//        //        s.addToTree(it);
//        s.addToBTree(it);
//    }
    for(int i=1;i<=7;i++)
    {
        V.push_back(TreeNode(i));
    }
    V[0].left = &V[1];
    V[0].right = &V[2];
    
    V[1].left = &V[3];
    V[1].right = &V[4];
    V[2].left = &V[5];
    V[2].right = &V[6];
    s.setBTreeRoot(&V[0]);
    s.set
    //s.printInOrderTraversal(s.getBTreeRoot());
    s.zigzag(s.getBTreeRoot());
    //s.SetNextRight(s.getBTreeRoot());
    //cout << "Tree is " << (s.IsSymmetricTree(s.getBTreeRoot())?"Symmetric":"Not Symmetric") << endl;
    //cout << "Tree min Depth : " <<s.minDepth(s.getBTreeRoot()) << endl;
    //cout << "Tree max Depth : " <<s.maxDepth(s.getBTreeRoot()) << endl;
    //vector<int> SA = {1,2,3,4,5,6,7,8,9,10,11};
//    vector<int> SA = {1,2,2,2,4,4,4,4};
//    cout << "InOrder traversaal of sorted array:";
//    s.printInOrderTraversal(s.sortedArrayToBST(SA));
    // vector<double> CA = {0.1,1.1,2.1,3.1,4.1,5.1,6.1,7.1};
    //for(auto i: CA)
    //cout << "Closest Value to " << 2.1 << " is " << (s.closestValue(s.sortedArrayToBST(SA), 2.1)) << endl;
    //    cout << "Inverting Tree ";
    //    s.printInOrderTraversal(s.sortedArrayToBST(SA));
    //    cout << endl;
    //    cout << " TO " << endl;
    //    s.printInOrderTraversal(s.invertTree(s.sortedArrayToBST(SA)));
    // cout << "Tree is " << (s.isBalanced(s.sortedArrayToBST(SA))?"Yes":"No") << endl;;
//    TreeNode *tmproot = s.sortedArrayToBST(SA);
//    cout << "Mode of the tree: [";
//    for(auto i:s.findMode(tmproot) )
//        cout << i << ",";
//    cout << endl;
//    //TreeNode *lca = s.LCA(tmproot,s.searchForNode(tmproot, 4),s.searchForNode(tmproot,5));
//    //cout << "LCA of 4 and 5:"<<(lca?lca->val:0)<<endl;
//    cout << "Max Path Sum:" << s.maxPathSum(tmproot) << endl;
    
    return 0;
}
