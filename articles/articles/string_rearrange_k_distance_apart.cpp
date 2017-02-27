//
//  string_rearrange_k_distance_apart.cpp
//  articles
//
//  Created by Vyas on 2/23/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include "map"
#include <queue>
using namespace std;

struct Compare {
    inline bool operator()(pair<char,int> &lhs, pair<char, int> &rhs) {
        cout << "comparing " << lhs.first << "-" << lhs.second << " with " << rhs.first << "-" << rhs.second <<endl;
        if(lhs.second == rhs.second)
            return (lhs.first-'a') > (rhs.first - 'a');
        return lhs.second <= rhs.second;
    }
};
string
rearrange_string_with_k_distance(string input, int distance) {
    string result;
    std::priority_queue<pair<char,int>,vector<pair<char, int>>, Compare> pq;
    std::deque<pair<char,int>> Q;
    map<char, int> mymap;
    for(auto i = 0;i<input.size();i++){
        auto t = mymap.find(input[i]);
        if(t==mymap.end()){
            mymap[input[i]] = 1;
        } else {
            mymap[input[i]]++;
        }
    }
    for(auto t : mymap){
        pq.push(t);
    }
    auto d = distance;
    while(pq.size()) {
        auto t = pq.top();
        pq.pop();
        result += t.first;
        t.second--;
        if(t.second)
            Q.push_back(t);
        d--;
        if(d == 0) { //push all queue elements back into the priority queue.
            for(auto q : Q ){
            	pq.push(q);
                Q.pop_front();
            }
            d = distance;
        } else {
            if(Q.size() !=0 && pq.size()==0) {
                return "";//Not Possible " + result;
            }
        }
    }
    return result;
}


int main() {
    string input = "aabbccdd"; int distance = 4;
    cout << "Rearranging " <<input<< " to " << rearrange_string_with_k_distance(input,distance) << endl;
    return 0;
}
