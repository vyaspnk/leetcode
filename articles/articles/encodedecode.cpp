//
//  encodedecode.cpp
//  articles
//
//  Created by Vijetha Malla on 2/25/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
string
encode(vector<string> V) {
    string R;
    if(V.size()==0)
        return R;
    for(auto v:V) {
        auto vsize = v.size();
        R+=to_string(vsize)+":"+v;
    }
    return R;
}

vector<string>
decode(string str) {
    vector<string> V;
    if(str.size()==0)
        return V;
    std::string::size_type sz;
    int val = std::stoi (str,&sz);

    do {
        str.erase(0,sz+1);
        auto s = str.substr(0,val);
		V.push_back(s);
        str.erase(0,val);
        if(str.size()==0)
            break;
        val = std::stoi (str,&sz);
    } while(str.size());
    return V;
}

int main(){
    vector<string> V;
    V.push_back("abc");
    V.push_back("1234");
    V.push_back(":");
    V.push_back(" ");
    cout << "encode: " << encode(V) << endl;
    decode(encode(V));
    return 0;
}
