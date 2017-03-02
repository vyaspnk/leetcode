//
//  strstr.c
//  articles
//
//  Created by Vijetha Malla on 3/1/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include <stdio.h>
const char* StrStr(const char *str, const char *pattern) {
    if (!*pattern) return str; //return if target is NULL
    char *ptr = (char*)str; // iterator for input string (starting from beginning of the string).
    char *ptrend = str;
    char *patttmp = pattern;
    while(*++patttmp) ptrend++; // assuming input string length is greater than pattern string.
    while (*ptrend) {
        char *tmp = ptr; //tmp points to the beginning of the matching portion of the string.
        char *pat = (char*)pattern; //iterator or pattern.
        while (*ptr && *pat && *ptr == *pat) { ptr++; pat++; } 	// keeping moving both input and pattern iterators
        														// if char at input iterator matches char at pattern iterator..
        if (!*pat) return tmp; 	// return string beginning from tmp as a result if pattern itertor reaches end.
        ptr = tmp + 1; 			// match failed for current substring. Try with substring+1;
        ptrend++;
    }
    return NULL;
}

int main() {
    char *pat = "abc";
    char *str = "jasdabaknsdabcaksdka";
    printf("%s\n",StrStr(str,pat));
    return 0;
}
