//
//  lrucache.cpp
//  list
//
//  Created by Vijetha Malla on 2/21/17.
//  Copyright © 2017 vy. All rights reserved.
//

#include "lrucache.hpp"
#include <iostream>

using namespace std;
using namespace cache;

class LRUCache {
    int capacity;
    typedef typename std::pair<int, int> CachePair;
    std::list<CachePair> Cache;
    typedef typename std::list<CachePair>::iterator list_iterator_t;
    unordered_map<int, list_iterator_t> LRUMap;
public:
    LRUCache(int val): capacity(val)  {
        
    }
    
    int get(int input) {
        int ret=-1;
        auto keymap = keymapper.find(input);
        if(keymap == keymapper.end()) {
            cout << "Key: " << input << " not found." << endl;
            return ret;
        } else {
            valueset.splice(valueset.begin(), valueset, keymap->second);
            return *keymap->second;
        }
    }

    void set(int input) {
        auto kt = keymapper.find(input);
        valueset.push_front(input);

        if(kt != keymapper.end()){
            valueset.erase(kt->second);
            keymapper.erase(kt);
        }
        keymapper[input] = valueset.begin();

        if(valueset.size() > max_size){
            auto k = valueset.end();
            k--;
            keymapper.erase(keymapper.find(*k));
            valueset.pop_back();
        }
    }

    bool exists(int input) {
        return (keymapper.find(input)==keymapper.end())?false:true;
    }
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
