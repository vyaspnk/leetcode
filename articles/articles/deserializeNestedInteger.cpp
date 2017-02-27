//
//  deserializeNestedInteger.cpp
//  articles
//
//  Created by Vijetha Malla on 2/24/17.
//  Copyright © 2017 vyas. All rights reserved.
//
#include <iostream>
#include "sstream"
#include <vector>
#include <list>
using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 */
  class NestedInteger {
    public:
      // Constructor initializes an empty nested list.
      NestedInteger();
 
      // Constructor initializes a single integer.
      NestedInteger(int value);
 
      // Return true if this NestedInteger holds a single integer, rather than a nested list.
      bool isInteger() const;
 
      // Return the single integer that this NestedInteger holds, if it holds a single integer
      // The result is undefined if this NestedInteger holds a nested list
      int getInteger() const;
 
      // Set this NestedInteger to hold a single integer.
      void setInteger(int value);
 
      // Set this NestedInteger to hold a nested list and adds a nested integer to it.
      void add(const NestedInteger &ni);
 
      // Return the nested list that this NestedInteger holds, if it holds a nested list
      // The result is undefined if this NestedInteger holds a single integer
       const vector<NestedInteger> &getList() const;
  };
 
class Solution {
private:
    std::string& trim_right_inplace(
                                    std::string&       s,
                                    const std::string& delimiters )
    {
        return s.erase( s.find_last_not_of( delimiters ) + 1 );
    }
    
    std::string& trim_left_inplace(
                                   std::string&       s,
                                   const std::string& delimiters )
    {
        return s.erase( 0, s.find_first_not_of( delimiters ) );
    }
    
    std::string& trim_inplace(
                              std::string&       s,
                              const std::string& delimiters )
    {
        return trim_left_inplace( trim_right_inplace( s, delimiters ), delimiters );
    }
    NestedInteger deserialize(istringstream &in) {
        int num;
        if(in >> num)
            return (NestedInteger(num));
        in.clear();
        in.get();
        NestedInteger list;
        while(in.peek()!=']') {
            list.add(deserialize(in));
            if(in.peek() == ',')
                in.get();
        }
        in.get();
        return list;
    }
public:
    NestedInteger deserialize(string s) {
        istringstream in(s);
        return deserialize(in);
//        NestedInteger R;
//        
//        if(s.substr(0,1) == "[") {
//            trim_left_inplace(s, "[");
//            R.add(deserialize(s));
//        }
//        trim_left_inplace(s, "],");
//        
//        std::string::size_type sz;
//        int val = std::stoi (s,&sz);
//        auto currentlist = R.getList();
//        currentlist.push_back(NestedInteger(val));
//        s.erase(0,sz);
//        if(s.substr(0,1) == ",") trim_left_inplace(s, ",");
//        
//        if(s.size()!=0)
//            currentlist.push_back(deserialize(s));
//        return R;
    }
};
