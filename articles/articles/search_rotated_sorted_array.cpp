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
bool binaryS(int A[],int N, int val) { // binary seach in A
    int b = 0;
    int e = N-1;
    if(A[b] == val || A[e]==val)
        return true;
    if(val <  A[b] || val > A[e])
        return false;
    int m = (e-b)/2;
    while(m >= b) {
        if(val == A[m])
            return true;
        if(val > A[m]) {
            b = m;
        } else {
            e = m;
        }
        m = m + (e-b)/2;
    }
    return false;
}
bool
search_rotated_sorted_array(int A[], int N, int val) {
    
    int b = 0;
    int e = N-1;
    if(A[b] < A[e]) { // not rotated
        return binaryS(&A[b],e-b+1,val);
    }
    if( e-b == 1) {
        return (A[b]==val||A[e]==val);
    };
    
    int m = (e - b)/2;
    while(m>b) {
        if( val == A[m])
            return true;
        //find the minimum element.
        if(A[b] > A[m]) {
            e = m;
            m = b+(e-b)/2;
        } else {
            if(val > A[m]) {
                return binaryS(&A[m], N-m, val);
            }else {
                return binaryS(&A[b], m-b, val);
            }
        }
	}
    return false;
}

int main(){
    int A[6] = {5,6,1,2,3,4};
    int val = 2;
    cout << "Val :" << val << (search_rotated_sorted_array(A, 6, val)?" found.": " not found.\n");
    return 0;
}
