/**
 * Chapter 9  --  9.1
 * Write a method to compute all permutations of a string.
 */

/**
 * Author: Teddy
 * Date: 29-01-2015
 */

/**
 * Analysis:
 * Backtracking solution: each character be used or not be used, TIME: O(n ^ n)
 * DP solution: permutation(n) = insert n into permutation(n - 1)
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Backtracking solution
 */

void recursion(string str, vector<bool> used, string p,
			   vector<string> &permutations){

	int len = str.size();

	if(p.size() == len){
		permutations.push_back(p);
		return;
	}

	for(int i = 0; i < len; i++){
		if(!used[i]){
			used[i] = true;
			recursion(str, used, p + str[i], permutations);
			used[i] = false;
		}
	}

}

vector<string> bt(string str){

	int len = str.size();
	vector<string> permutations;

	if(len <= 0){
		return permutations;
	}

	vector<bool> used(len, false);
	recursion(str, used, "", permutations);

	return permutations;
}

/**
 * DP solution
 */

vector<string> genPer(vector<string> &permutations, char c){
	vector<string> p;
	
	for(int i = 0; i < permutations.size(); i++){
		string s = permutations[i];
		int len = s.size();
		for(int i = 0; i < len; i++){
			p.push_back(s.substr(0, i - 0) + c + s.substr(i, len - i));
		}
		p.push_back(s + c);
	}

	return p;
}

vector<string> dp(string str){

	int len = str.size();
	vector<string> permutations;
	
	if(len <= 0){
		return permutations;
	}

	permutations.push_back("");

	for(int i = 0; i < len; i++){
		permutations = genPer(permutations, str[i]);
	}

	return permutations;

}

/**
 * Main function
 * normal case, edge case.
 */

void printStr(vector<string> strs){
	cout << strs.size() << " results in total:" << endl;
	for(int i = 0; i < strs.size(); i++){
		cout << strs[i] << endl;
	}
	cout << endl;
}

int main(){

	string cases[4] = {"", "a", "ab", "abcd"};

	for(int i = 0; i < 4; i++){
		cout << "Permutations of \"" << cases[i] << "\" :" << endl;
		cout << "-------Backtracking-------" << endl;
		printStr(bt(cases[i]));
		cout << "----Dynamic programming----" << endl;
		printStr(dp(cases[i]));
	}

	return 0;
}