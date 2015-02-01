/**
 * Chapter 1  --  1.3
 * Given two strings, write a method to decide if one is a permutation of the
 * other.
 */

/**
 * Author: Teddy
 * Date: 01-02-2015 
 */

/**
 * Analysis:
 * 1. Hash solution: put the characters to a hash, count them, if the count is
 *                   the same, return true, otherwise, return false.
 * 2. Sort solution: sort two strings, then compare them.
 */ 

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Hash solution
 * hash is implemented by a C++ STL map.
 * Time:  O(n)
 * Space: O(n)
 */
bool hash1(string s1, string s2){
    
    int len = s1.size();
    
    if(len != s2.size() || len <= 0){
        return false;
    }

    map<char, int> hash;

    // build hash
    for(int i = 0; i < len; i++){
        if(hash.find(s1[i]) == hash.end()){
            hash[s1[i]] = 1;
        }
        else{
            hash[s1[i]]++;
        }
    }

    // check
    for(int i = 0; i < len; i++){
        if(hash.find(s2[i]) == hash.end() || hash[s2[i]] <= 0){
            return false;
        }
        hash[s2[i]]--;
    }

    // because the length is the same, so if the checking loop did not return 
    // false, these two strings are permutations.
    return true;
}

/**
 * Hash solution
 * hash is implemented by a 256 size array, more fast than map.
 * Time:  O(n)
 * Space: O(n)
 */
bool hash2(string s1, string s2){
    
    int len = s1.size();
    
    if(len != s2.size() || len <= 0){
        return false;
    }

    int hash[256] = {0};

    // build hash
    for(int i = 0; i < len; i++){
        hash[s1[i]]++;
    }

    // check
    for(int i = 0; i < len; i++){
        if(hash[s2[i]] <= 0){
            return false;
        }
        hash[s2[i]]--;
    }

    // because the length is the same, so if the checking loop did not return 
    // false, these two strings are permutations.
    return true;
}

/**
 * Sort solution
 * Time: O(nlogn)
 * Space: O(1)
 */
bool sorts(string s1, string s2){

    int len = s1.size();

    if(len != s2.size() || len <= 0){
        return false;
    }

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for(int i = 0; i < len; i++){
        if(s1[i] != s2[i]){
            return false;
        }
    }

    return true;
}


/**
 * Main function
 * normal case, edge case.
 */
int main(){

    vector<string> s1s;
    s1s.push_back("");
    s1s.push_back("abc");
    s1s.push_back("abca");
    s1s.push_back("abc &");
    s1s.push_back("ab cd a");
    s1s.push_back("abcd&&");

    vector<string> s2s;
    s2s.push_back("a");
    s2s.push_back("cba");
    s2s.push_back("aabc");
    s2s.push_back(" &bca");
    s2s.push_back("abcd a");
    s2s.push_back("&dcba&");

    for(int i = 0; i < s1s.size(); i++){
        cout << "Case " << i << " : \""
             << s1s[i] << "\" & \"" << s2s[i] << "\"" << endl;
        cout << "hash1: " << hash1(s1s[i], s2s[i]) << endl;
        cout << "hash2: " << hash2(s1s[i], s2s[i]) << endl;
        cout << "sort:  " << sorts(s1s[i], s2s[i]) << endl;
    }

    return 0;
}