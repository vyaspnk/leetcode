//
//  unique_triplets.cpp
//  articles
//
//  Created by Vyas on 2/23/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<vector<int>>
unique_triplets(vector<int> &array, int &sum){
    set<vector<int>> triplets;
    int cnt = 0;
    int n = array.size();
    int i =0;
    int j = 0;
    int k = 0;
    for(i = 0; i<n;i++){
        for(j = i+1, k = n-1; j< n && k>j;) {
            if( array[i]+array[j] == sum - array[k]) {
                vector<int> V;
                V.push_back(i); V.push_back(j); V.push_back(k);
                j++;
                k--;
                triplets.insert(V);
            } else if(array[i]+array[j] < sum - array[k])
                j++;
            else
                k--;
        }
    }
    return triplets;
}

int main() {
    vector<int> array = {-3,-2,-1,0,1,2,3,4,5,6};
    auto sum = 0;
    set<vector<int>> T = unique_triplets(array, sum);
    for(auto t: T) {
        cout << "[ ";
        for(auto v: t){
            cout << v << ",";
        }
        cout << "] --> ";
        cout << "[ ";
        for(auto v: t){
            cout << array[v] << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}
