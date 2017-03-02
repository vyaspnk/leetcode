//
//  majorityElement1.cpp
//  articles
//
//  Created by Vijetha Malla on 2/26/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
//Boyer-Moore Voting Algorithm for 1,2,3. k elements whose frequency exceeds N/(k+1)
//eg: Majority Element: if K = 1; implies find 1 element which repeats more than 1/2 the list.
//eg: Majority 2 Elements: if K=2; implies find 2 elements which repeat more than 1/3 list.
//
//O(n) time and O(1) space complexity


vector<int>
majorityElement(vector<int>& nums) {
    int cntA = 0, cntB = 0;
    // if(nums.size()<=2)
    //     return nums;
    auto A = 0;
    auto B = 1;
    
    vector<int> R;
    for(int i = 0; i<nums.size();i++){
        if(A == nums[i]){
            cntA++;
        }else if(B == nums[i]){
            cntB++;
        }else if(cntA==0){
            A = nums[i];
            cntA=1;
        }else if(cntB==0){
            B = nums[i];
            cntB=1;
        } else {
            cntA--;
            cntB--;
        }
    }
    cntA=0;
    cntB=0;
    for(auto r:nums){
        if(r==A) cntA++;
        else if(r==B) cntB++;
    }
    if(cntA > nums.size()/3)
        R.push_back(A);
    if(cntB > nums.size()/3)
        R.push_back(B);
    return R;
    
    
//    unordered_map<int,int> count;
//    for(auto n:nums) {
//        count[n]+=1;
//        if(count[n] > nums.size()/2)
//            return n;
//    }
//    return nums[0];
}
