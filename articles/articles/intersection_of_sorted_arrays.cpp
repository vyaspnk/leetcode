//
//  intersection_of_sorted_arrays.cpp
//  articles
//
//  Created by Vyas on 2/23/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
int
bounds(int val, vector<int> B) { //a.size() < b.size()
    int e = (int)B.size()-1;
    int b = 0;
    if(e-b<=1)
        return b;
    int  m = (e-b);
    while(m > b) {
        if(val == B[m])
            return m;
        if(val < B[b])
            return b;
        if(val > B[e])
            return e;
    	if(val > B[m]  && val < B[e] ) {
                b = m;
        } else if(val > B[b] && val < B[m] ) {
                e = m;
        }
        m = m + (e - b)/2;
    }
    return m;
}

int main() {
    vector<int> A = {1,2,3,4,5};
    vector<int> B = {2,3,5,6,7};
    
    if(A.size() > B.size()){
        auto t = A;
        A = B;
        B = t;
    }
    vector<int> R;
    int i = 0, ii = A.size()-1;
    auto j  = bounds(A[i], B);
    auto jj = bounds(A[ii], B);
    
    while(i<=ii && j<=jj) {
        if(A[i] == B[j]) {
            R.push_back(A[i]);
            i++; j++;
        } else if(A[i]>B[j]) {
            j++;
        } else {
            i++;
        }
        
    }
    for(auto x:R) {
        cout << x << " " ;
    }
    
    return 0;
}
