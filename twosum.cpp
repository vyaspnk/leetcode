//
//  twosum.cpp
//  articles
//
//  Created by Vijetha Malla on 2/26/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> R;
    unordered_map<int, int> diff;
    for( auto i = 0; i< nums.size();i++) {
        int delta = target - nums[i];
        auto it = diff.find(nums[i]);
        if(it == diff.end()){
            diff[delta] = i;
        } else {
            R.push_back(std::min(i,it->second));
            R.push_back(std::max(i,it->second));
            return R;
        }
    }
    return R;
}
int main() {
    vector<int> nums = {7,2,13,11};

    auto R = twoSum(nums, 9);
    for(auto i:R)
        cout << i << " ";
    cout << endl;
    return 0;
}
