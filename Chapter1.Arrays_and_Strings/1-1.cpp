/**
 * Chapter 1  --  1.1
 * Implement an algorithm to determine if a string has all unique characters.
 * What if you cannot use additional data structures?
 */

/**
 * Author: Teddy
 * Date: 27-01-2015 
 */

/**
 * Analysis:
 * 1. Naive solution: travle the whole string, check each character appears
 *                    before, it will use no additional space, but will use
 * 					  more time.
 * 2. Cache solution: cache the character travled in a hash, check next
 *                    character exists in the hash or not. this solution will
 *                    use additional data structure, but will very fast.
 */ 

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Naive solution
 * Time:  O(n^2)
 * Space: O(0)
 */
bool naive(string s){
	
	int len = s.size();

	if(len <= 0){
		return false;
	}

	if(len > 256){
		return true;
	}

	for(int i = 1; i < len; i++){
		for(int j = 0; j < i; j++){
			if(s[i] == s[j]){
				return true;
			}
		}
	}

	return false;
}

/**
 * Cache solution 1
 * using an array as hash, which length is 256 bytes, each cell sign a character
 * Time:  O(n)
 * Sapce: O(1)
 */

bool cache1(string s){

	int len = s.size();

	if(len <= 0){
		return false;
	}

	if(len > 256){
		return true;
	}

	bool cache[256] = {false};

	for(int i = 0; i < len; i++){
		char c = s[i];
		if(cache[c]){
			return true;
		}
		cache[c] = true;
	}

	return false;
}

/**
 * Cache solution 2
 * using 256 bits as hash, each bit sign a character
 * Time:  O(n)
 * Sapce: O(1)
 */
bool cache2(string s){

	int len = s.size();

	if(len <= 0){
		return false;
	}

	if(len > 256){
		return true;
	}

	int cache[8] = {0};

	for(int i = 0; i < len; i++){
		char c = s[i];
		int index = c / 32;
		int bits = c % 32;
		if(cache[index] & 1 << bits){
			return true;
		}
		cache[index] |= 1 << bits;
	}

	return false;
}

/**
 * Main function
 * normal case, edge case.
 */
int main(){

	vector<string> cases;
	cases.push_back("");
	cases.push_back("abc");
	cases.push_back("abca");
	cases.push_back("abc &");
	cases.push_back("ab cd a");
	cases.push_back("abcd&&");
	cases.push_back("abdfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");

	for(int i = 0; i < cases.size(); i++){
		cout << "case " << i << " result using naive:   " <<
				naive(cases[i]) << endl;
		cout << "case " << i << " result using cache 1: " <<
				cache1(cases[i]) << endl;
		cout << "case " << i << " result using cache 2: " <<
				cache2(cases[i]) << endl;
	}

	return 0;
}