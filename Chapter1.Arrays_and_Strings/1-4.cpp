/**
 * Chapter 1  --  1.4
 * Write a method to replace all spaces in a string with "%20". You may assume
 * that the string has sufficient space at the end of the string to hold the
 * additional character, and that you are given the "true" length of the string.
 * (Note: if implementing in Java, please use a character array so that you can
 * perform this operation in place.)
 */

/**
 * Author: Teddy
 * Date: 01-02-2015 
 */

/**
 * Analysis:
 * 1. Naive solution: count the spaces and replace from the end.
 */ 

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Naive solution
 * Time:  O(n)
 * Space: O(n)
 */
string naive(string s, int l){

    if(l <= 0){
        return "";
    }

    string result;
    int spaces = 0;

    for(int i = 0; i < l; i++){
        spaces = s[i] == ' ' ? spaces + 1 : spaces;
    }

    int len = l + 2 * spaces;
    int back = len - 1;
    int front = l - 1;
    
    while(front >= 0){
        if(s[front] == ' '){
            s[back--] = '0';
            s[back--] = '2';
            s[back--] = '%';
        }
        else{
            s[back--] = s[front];
        }
        front--;
    }

    return s;
}

/**
 * Main function
 * normal case, edge case.
 */
int main(){

    vector<string> cases;
    cases.push_back("");
    cases.push_back("abc");
    cases.push_back("abc &  ");
    cases.push_back("ab cd a    ");
    cases.push_back("abcd&&");

    vector<int> lens;
    lens.push_back(0);
    lens.push_back(3);
    lens.push_back(5);
    lens.push_back(7);
    lens.push_back(6);

    for(int i = 0; i < cases.size(); i++){
        cout << "Source \"" << cases[i] << "\" to "
             << naive(cases[i], lens[i]) << endl;
    }

    return 0;
}