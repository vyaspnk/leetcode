//
//  numofislands.cpp
//  articles
//
//  Created by Vijetha Malla on 2/27/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
#include "unordered_map"
using namespace std;

void checkAndPush(vector<vector<char>>& grid, int row, int col) {
    if(row+1 < grid.size() && grid[row+1][col]=='1')
        Q.push(make_pair(row+1,col));
}
int numIslands(vector<vector<char>>& grid) {
    int cnt=0;
    int rows = grid.size();
    int cols = grid[0].size();
    for(auto i = 0; i < rows; i++) {
        for(auto j = 0; j < cols; j++) {
            if(grid[i][j] == '1') {
                grid[i][j] = '0';
                checkAndPush(grid,i,j)
            }
            else
                break;
        }
        cnt++;
    }
}
