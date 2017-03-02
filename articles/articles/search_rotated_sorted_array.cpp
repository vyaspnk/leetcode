//
//  search_rotated_sorted_array.cpp
//  articles
//
//  Created by Vyas on 2/23/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
/**
 * @brief - Iterative Binary Search implementation. Returns  *
 * the index of target if found, else returns -1             *
 * Time Complexity = O(lg n).   Space Complexity = O(1)      */
int binarySearch(vector<int>& nums, int first, int last, int target) {
    if(first < 0 || first > last) return -1;
    
    for(int mid; first <= last; ) {
        mid = first + (last - first) / 2;
        if(nums[mid] < target)          first = mid + 1;
        else if(nums[mid] > target)     last = mid - 1;
        else                            return mid;
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    if(nums.size() == 0)  return 0;
    int m = 0;
    /* If input is rotated, find index of smallest element    *
     * with Binary Search                                     */
    for(int b = 0, e = nums.size() - 1; b <= e && nums[b] > nums[e]; ) {
        /* If len is even, mid needs to be higher element      */
        m = b + (e - b) / 2;
        if((e-b+1) % 2 == 0)   m++;
        if(nums[m] > nums[b])  b = m;  /* Is [b, m] not-rotated*/
        else                   e = m-1;/* Is [m, e] not-rotated*/
    }
    int pivot = m;
    //cout << endl << "smallest @ " << pivot << endl;
    int ret = binarySearch(nums, 0, pivot-1, target);
    if(ret == -1)  ret = binarySearch(nums, pivot, nums.size()-1, target);
    
    return ret;
}


int main(){
    int A[6] = {5,6,1,2,3,4};
    int val = 2;
    cout << "Val :" << val << (search_rotated_sorted_array(A, 6, val)?" found.": " not found.\n");
    return 0;
}
