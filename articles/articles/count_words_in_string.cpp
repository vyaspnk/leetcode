//
//  main.cpp
//  articles
//
//  Created by Vijetha Malla on 2/23/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int
countwords(char *str) {
    char *p1 = str;
    bool inword = false;
    if(!p1)
        return 0;
    int cnt = 0;
    do {
        if(!inword && *p1 != ' '){
            inword = true;
            cnt++;
        }
        if(*p1 == ' '){
            inword = false;
        }
    
    } while (*(++p1)!='\0');
	return cnt;
}
int main(int argc, const char * argv[]) {
    std::cout << "#Words in Hello, World! are "<< countwords("Hello, World!\n") << endl;
    std::cout << "#Words in  , World! are "<< countwords(" , World!\n") << endl;
    std::cout << "#Words in Hello, World!  are "<< countwords("Hello, World! \n ") << endl;
    return 0;
}
