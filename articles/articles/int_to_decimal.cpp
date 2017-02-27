//
//  int_to_decimal.cpp
//  articles
//
//  Created by Vijetha Malla on 2/23/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include <stdio.h>

void putlong(unsigned int n) {
    
    if(n>10)
    	putlong(n/10);
    putchar(n%10+'0');
    return;
}

int main() {
    int n = 0;
    putlong(n);
    return 0;
}
