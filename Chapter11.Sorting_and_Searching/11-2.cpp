/**
 * Chapter 11  --  11.1
 * Write a method to sort an array of strings so that all the anagrams are next
 * each other.
 */

/**
 * Author: Teddy
 * Date: 02-02-2015 
 */

/**
 * Analysis:
 * 1. Hash solution: sort each string, then put them to the buckets.
 */

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Hash solution
 * Time:  O(n)
 * Space: O(n)
 */
vector<string> hash(vector<string> strs){

    int len = strs.size();
    vector<string> results;
    
    if(len <= 0){
        return results;
    }

    map<string, vector<string> > hash;
    map<string, vector<string> >::iterator iter;
    for(int i = 0; i < len; i++){
        string s = strs[i];
        sort(s.begin(), s.end());
        if(hash.find(s) == hash.end()){
            vector<string> e;
            e.push_back(strs[i]);
            hash[s] = e;
        }
        else{
            hash[s].push_back(strs[i]);
        }
    }

    for(iter = hash.begin(); iter != hash.end(); iter++){
        for(int i = 0; i < iter->second.size(); i++){
            results.push_back(iter->second[i]);
        }
    }
    
    return results;
}

/**
 * Main function
 * normal case, edge case.
 */
void printStr(vector<string> strs){
    for(int i = 0; i < strs.size(); i++){
        cout << strs[i] << endl;
    }
    cout << endl;
}

int main(){

    vector<string> cases;
    cases.push_back("father");
    cases.push_back("ab");
    cases.push_back("");
    cases.push_back("ababa");
    cases.push_back("ababa");
    cases.push_back("erthfa");
    cases.push_back("ba");
    cases.push_back("");

    printStr(hash(cases));

    return 0;
}