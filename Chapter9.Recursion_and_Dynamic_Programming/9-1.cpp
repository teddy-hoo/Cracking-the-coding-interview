/**
 * Chapter 9  --  9.1
 * A child is running up a staircase with n steps, and can hop either 1 step, 
 * 2 steps or 3 steps at a time. Implement a method to count how many possible
 * ways the child can run up the stairs.
 */

/**
 * Author: Teddy
 * Date: 29-01-2015
 */

/**
 * Analysis:
 * Backtracking solution: at each state, the child can hop 1 or 2 or 3 steps,
 *						  try these three possible, TIME: O(3^n)
 * DP solution: ways(n) = ways(n - 1) + ways(n - 2) + ways(n - 3)
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Backtracking solution
 */

void recursion(int n, int &ways){

	if(n == 0){
		ways++;
		return;
	}

	recursion(n - 1, ways);
	if(n >= 2){
		recursion(n - 2, ways);
		if(n >= 3){
			recursion(n - 3, ways);
		}
	}

}

int bt(int n){

	if(n <= 0){
		return 0;
	}

	int ways = 0;
	recursion(n, ways);

	return ways;
}

/**
 * DP solution
 */

int dp(int n){

	if(n <= 0){
		return 0;
	}

	vector<int> ways(n + 1, 0);
	ways[0] = 1;

	for(int i = 1; i <= n; i++){
		int currentWays = ways[i - 1];
		if(i >= 2){
			currentWays += ways[i - 2];
			if(i >= 3){
				currentWays += ways[i - 3];
			}
		}
		ways[i] = currentWays;
	}

	return ways.back();

}

/**
 * Main function
 * normal case, edge case.
 */

int main(){

	int cases[7] = {-1, 0, 1, 2, 3, 5, 30};

	for(int i = 0; i < 7; i++){
		cout << "Total " << cases[i] << " steps:" << endl;
		cout << "Backtracking:        " << bt(cases[i]) << endl;
		cout << "Dynamic programming: " << dp(cases[i]) << endl;
		cout << endl;
	}

	return 0;
}