//
//  lrucache.hpp
//  list
//
//  Created by Vijetha Malla on 2/21/17.
//  Copyright © 2017 vy. All rights reserved.
//

#ifndef lrucache_hpp
#define lrucache_hpp

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

namespace cache
{
    class lrucache {
    private:
        int max_size;
        std::unordered_map<int,std::list<int>::iterator> keymapper;
        std::list<int> valueset;
    public:
        lrucache(int capacity) : max_size(capacity){
            
        }

        int get(int);
        void set(int);
        bool exists(int input);
    };

}
#endif /* lrucache_hpp */
