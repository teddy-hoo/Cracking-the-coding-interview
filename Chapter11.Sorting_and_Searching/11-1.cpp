/**
 * Chapter 11  --  11.1
 * You are given two sorted arrays, A and B, where A has a large enouph buffer
 * at the end to hold B. Write a method to merge B into A in sorted order.
 */

/**
 * Author: Teddy
 * Date: 02-02-2015 
 */

/**
 * Analysis:
 * 1. Naive solution: merge the two arrays from back to front.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Naive solution
 * Time:  O(n)
 * Space: O(1)
 */
vector<int> naive(vector<int> v1, int l1, vector<int> v2, int l2){

    if(l1 <= 0){
        return v2;
    }

    if(l2 <= 0){
        return v1;
    }

    int p1 = l1 - 1;
    int p2 = l2 - 1;
    int p3 = l1 + l2 - 1;
    while(p1 >= 0 && p2 >= 0){
        if(v1[p1] > v2[p2]){
            v1[p3--] = v1[p1--];
        }
        else{
            v1[p3--] = v2[p2--];
        }
    }

    while(p2 >= 0){
        v1[p3--] = v2[p2--];
    }

    return v1;
}

/**
 * Main function
 * normal case, edge case.
 */
void printInt(vector<int> ints){
    for(int i = 0; i < ints.size(); i++){
        cout << ints[i] << endl;
    }
    cout << endl;
}

int main(){

    vector<int> int1(10);
    int1[0] = 1;
    int1[1] = 3;
    int1[2] = 5;
    int1[3] = 7;
    int1[4] = 9;

    vector<int> int2;
    int2.push_back(2);
    int2.push_back(4);
    int2.push_back(6);
    int2.push_back(8);
    int2.push_back(10);

    printInt(naive(int1, 5, int2, 5));

    return 0;
}