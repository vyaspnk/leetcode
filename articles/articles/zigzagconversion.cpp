//
//  zigzagconversion.cpp
//  articles
//
//  Created by Vijetha Malla on 2/25/17.
//  Copyright © 2017 vyas. All rights reserved.
//


//Convert String like ABCDEFGHIJKLMNOP to
//A - - G - - M
//B - F H - L N
//C E - I K - O
//D - - J - - P
//
//Solution: push elements into string[nrows] linearly till nrows and then start reversing when pushing when pushing
//

#include <iostream>
#include <vector>
using namespace std;
string convert(string s, int numRows) {
    vector<string> R(numRows);
    string Result;
    if(numRows<=1)
        return s;
    int step = 1;
    int row = 0;
    for(int i = 0; i < s.size(); i++) {
        R[row].push_back(s[i]);
        if(row==0)
            step = 1;
        if(row == numRows-1)
            step = -1;
        row = row + step;
    }
    
    for(auto str: R){
        Result+=str;
    }
    return Result;
}

int main() {
    string s = "ABCDEFGHIJKLMNOP";
    cout << s << endl;
    cout << convert(s, 4)<< endl;
    return 0;
}
