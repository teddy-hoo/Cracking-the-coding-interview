/**
 * Chapter 1  --  1.2
 * Implement a function void reverse(char *str) in C or C++ which reverses a
 * null-terminated string.
 */

/**
 * Author: Teddy
 * Date: 27-01-2015 
 */

/**
 * Analysis:
 * 1. Naive solution: use extra space to construct a new reversed string
 * 2. In-place solution: reverse the string in-place
 */ 

#include <iostream>
#include <stdlib.h>

using namespace std;

/**
 * Naive solution
 * this function may cause memory leak, not a good solution
 * Time:  O(n)
 * Space: O(n)
 */
void naive(char *&str){
    
    if(str == NULL){
        return;
    }

    int len = 0;
    while(str[len] != '\0'){
        len++;
    }

    char *newStr = (char *)malloc(sizeof(char) * len);

    for(int i = len - 1; i >= 0; i--){
        newStr[len - i - 1] = str[i];
    }
    newStr[len] = '\0';

    str = newStr;
}

/**
 * In-place solution
 * Time:  O(n)
 * Sapce: O(1)
 */

void inPlace(char *str){

    if(str == NULL){
        return;
    }

    int len = 0;

    while(str[len] != '\0'){
        len++;
    }

    for(int i = 0; i < len / 2; i++){
        char tmp = str[i];
        *(str + i) = str[len - i - 1];
        str[len - i - 1] = tmp;
    }

}

/**
 * Main function
 * normal case, edge case.
 */
int main(){

    char *str = NULL;
    naive(str);
    cout << "str \"\" reversed by naive:      " << str << endl;
    str = NULL;
    inPlace(str);
    cout << "str \"\" reversed by inPlace:    " << str << endl;
    str = "abc";
    naive(str);
    cout << "str \"abc\" reversed by naive:   " << str << endl;
    str = "abc";
    inPlace(str);
    cout << "str \"abc\" reversed by inPlace: " << str << endl;
    str = "ab";
    naive(str);
    cout << "str \"ab\" reversed by naive:    " << str << endl;
    str = "ab";
    inPlace(str);
    cout << "str \"ab\" reversed by inPlace:  " << str << endl;

    return 0;
}