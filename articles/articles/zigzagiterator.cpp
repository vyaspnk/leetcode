//
//  zigzagiterator.cpp
//  articles
//
//  Created by Vyas on 2/24/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class ZigzagIterator {
    bool first;
    vector<int> r;
    vector<int>::iterator it1,et1;
    vector<int>::iterator it2,et2;
    vector<int>::iterator c;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        it1 = v1.begin(); et1 = v1.end();
        it2 = v2.begin(); et2 = v2.end();
        first = true;
        if(it1!=et1) c = it1;
        else { c = it2; first = false; }
    }
    int next() {
        int tmp = *c;
        if(first){
            it1++;
            if(it2!=et2) {
                c = it2;
                first = false;
            }
            else {
                c = it1;
                first = true;
            }
        } else {
            it2++;
            if(it1!=et1) {
                c = it1;
                first = true;
            }
            else {
                c = it2;
                first = false;
            }
        }
        return tmp;
    }
    
    bool hasNext() {
        return (c!=et1 && c!=et2);
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
