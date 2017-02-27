//
//  Invert_A_BST.cpp
//  Trees
//
//  Created by Vyas on 2/17/17.
//  Copyright © 2017 vyas. All rights reserved.
//


#include <iostream>
#include "stdlib.h"
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


vector<int> V= {1,2,3,4,5};
vector<vector<int>> M = {V,V};

void print_spiral(vector<vector<int>> mat, int m, int n, int k ) {
    if (m <= 0 || n <= 0)
        return;
    if (m == 1) {
        for (int j = 0; j < n; j++)
            cout << mat[k][k+j] << " ";
        return;
    }
    if (n == 1) {
        for (int i = 0; i < m; i++)
            cout << mat[k+i][k] << " ";
        return;
    }
    // print from top left
    for (int j = 0; j < n - 1; j++)
        cout << mat[k][k+j] << " ";
    // print from top right
    for (int i = 0; i < m - 1; i++)
        cout << mat[k+i][k+n-1] << " ";
    // print from bottom right
    for (int j = 0; j < n - 1; j++)
        cout << mat[k+m-1][k+n-1-j] << " ";
    // print from bottom left
    for (int i = 0; i < m - 1; i++)
        cout << mat[k+m-1-i][k] << " ";
    
    print_spiral(mat, m-2, n-2, k+1);
}

void print_spiral_helper(vector<vector<int>> mat, int m, int n) {
    print_spiral(mat, m, n, 0);
}
int main() {
    print_spiral_helper(M, M[0].size(), M.size());
}
