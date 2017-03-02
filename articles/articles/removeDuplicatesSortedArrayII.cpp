//
//  removeDuplicatesSortedArrayII.cpp
//  articles
//
//  Created by Vijetha Malla on 3/2/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    int sz = (int)nums.size();
    if(sz<=1) return sz;
    int first = 0;
    int last = 0;
    while(last+1<nums.size()) {
        while(nums[first] == nums[last+1]) last++;
        while(first < last-1 && nums[first] == nums[last]) {
            nums.erase(nums.begin()+first);
        	last--;
    	}
        last++;
        first = last;
	}
    return (int)nums.size();
}


int main() {
    vector<int> V = {-3,-1,-1,0,0,0,0};
    cout << removeDuplicates(V);
    for(auto i:V)
        cout << i << ", ";
    cout <<endl;
    return 0;
}
