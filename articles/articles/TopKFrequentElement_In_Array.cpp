
#include <iostream>
#include "sstream"
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;
typedef std::pair<int,int> pii_t;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mymap;
        priority_queue<pii_t, vector<pii_t>> mypq;
        vector<int> R;
        
        for(auto n : nums) mymap[n]++; //count the frequencies if elements in the array.
        //push the key+freq pairs to the my priority Q. ordered by freq.
        /* Priority Q init without Comp() will use the first less<T> which keeps highest <T> at the top(back) */
        for(const auto &m : mymap) mypq.push(make_pair(m.second,m.first));
//        assert(mypq.size()>=k);
        while(k-->0) {R.push_back(mypq.top().second); mypq.pop();}
        return R;
    }
};
