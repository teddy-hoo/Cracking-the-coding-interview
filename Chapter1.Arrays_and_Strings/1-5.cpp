/**
 * Chapter 1  --  1.5
 * Implement a method to perform basic string compression using the counts of
 * repeated characters. For example, the string aabcccccaaa would become
 * a2b1c5a3. If the "compressed" string would not become smaller than the
 * original string, your method should return the original string.
 */

/**
 * Author: Teddy
 * Date: 01-02-2015 
 */

/**
 * Analysis:
 * 1. Naive solution: count the characters, then compare it to the length of
 *                    original string, if larger, compress it.
 */ 

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

/**
 * Naive solution
 * Time:  O(n)
 * Space: O(n)
 */
int countBit(vector<int> counts){
    int total = 0;

    for(int i = 0; i < counts.size(); i++){
        int c = counts[i] / 10;
        total += 2;
        while(c > 0){
            total++;
            c /= 10;
        }
    }

    return total;
}

string intToStr(int i){
    string s;
    while(i > 0){
        int tmp = i % 10;
        s += tmp + '0';
        i /= 10;
    }

    // reverse the result string
    int begin = 0;
    int end = s.size() - 1;
    while(begin < end){
        char tmp = s[begin];
        s[begin] = s[end];
        s[end] = tmp;
        begin++;
        end--;
    }
    return s;
}

string naive(string s){

    int len = s.size();

    if(len <= 0){
        return "";
    }

    vector<char> chars;
    vector<int> counts;
    string compressed;

    chars.push_back(s[0]);
    counts.push_back(1);

    for(int i = 1; i < len; i++){
        if(s[i] == s[i - 1]){
            counts.back()++;
        }
        else{
            chars.push_back(s[i]);
            counts.push_back(1);
        }
    }

    if(countBit(counts) >= len){
        return s;
    }

    for(int i = 0; i < chars.size(); i++){
        compressed += chars[i] + intToStr(counts[i]);
    }    

    return compressed;
}

/**
 * Main function
 * normal case, edge case.
 */
int main(){

    vector<string> cases;
    cases.push_back("");
    cases.push_back("abc");
    cases.push_back("aaabbbbbcdcccdeefffffff");
    cases.push_back("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcdefghijklmnopqrstabcdefgabcdefabcdefabcdefabcdefghijkmabcdabcdabcdabcd");
    cases.push_back("aaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbccccccccccccccccccc");
    cases.push_back("aaaaaaaaaaaaaaaaaaaaaaaa");

    for(int i = 0; i < cases.size(); i++){
        cout << "Source " << cases[i] << ", compressed: "
             << naive(cases[i]) << endl;
    }

    return 0;
}
