/**
 * Chapter 11  --  11.3
 * Given a sorted array of n integers that hash been rotated on unknown number
 * of times, write code to find an element in the array. You may assume that the
 * array was originally sorted in increasing order.
 * EXAMPLE
 * Input: find 5 in {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14}
 * Output: 8 (the index of 5 in the array)
 */

/**
 * Author: Teddy
 * Date: 02-02-2015 
 */

/**
 * Analysis:
 * 1. Binary search solution: binary search, two conditions:
                              1) begin < middle and middle > end
                                a. iterate right if begin > target
                                b. iterate left otherwise
                              2) begin > middle and middle < end
                                a. iterate left if middle > target
                                b. iterate right otherwise
                              3) begin < middle and middle < end
                                a. iterate left if middle > target
                                b. iterate right otherwise
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Binary search solution
 * suppose there is no duplicate numbers in the array.
 * Time:  O(n)
 * Space: O(1)
 */
int bs(vector<int> nums, int target){

    int len = nums.size();
    
    if(len <= 0){
        return -1;
    }

    int begin = 0;
    int end = len - 1;
    while(begin <= end){
        int middle = begin + ((end - begin) >> 1);
        if(nums[middle] == target){
            return middle;
        }
        if(nums[middle] >= nums[begin] && nums[middle] >= nums[end]){
            if(nums[begin] > target){
                begin = middle + 1;
            }
            else{
                end = middle - 1;
            }
        }
        else{
            if(nums[middle] > target){
                end = middle - 1;
            }
            else{
                begin = middle + 1;
            }
        }
    }

    return -1;
}

/**
 * Main function
 * normal case, edge case.
 */
void printInt(vector<int> nums){
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << ": " << endl;
}

int main(){

    vector<vector<int> > cases;
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> one(A, A + 8);
    cases.push_back(one);
    int B[] = {6, 7, 8, 1, 2, 3, 4, 5};
    vector<int> two(B, B + 8);
    cases.push_back(two);
    int C[] = {4, 5, 6, 7, 8, 1, 2, 3};
    vector<int> three(C, C + 8);
    cases.push_back(three);

    for(int i = 0; i < 3; i++){
        cout << "Find 2 in ";
        printInt(cases[i]);
        cout << "Pos: " << bs(cases[i], 2) << endl;
    }

    return 0;
}