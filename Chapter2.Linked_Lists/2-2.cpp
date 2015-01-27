/**
 * Chapter 2  --  2.2
 * Implement an algorithm to find the kth to last element of a singly linked
 * list.
 */

/**
 * Author: Teddy
 * Date: 27-01-2015 
 */

/**
 * Analysis:
 * 1. Naive solution: two round travlsal, first round get the length of the
 *                    list, second round get the kth element.
 * 2. Two pointer solution: use two pointer, fast one and slow one, when fast
 *                          one goes out k steps, the slow begin to go, when 
 *                          fast one reach the end, the slow one is kth.
 */ 

#include <iostream>

using namespace std;

/**
 * Linked List
 */
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int v): val(v), next(NULL){}
};

/**
 * Naive solution
 * Time:  O(n)
 * Space: O(1)
 */
int naive(ListNode *head, int k){
    
    if(head == NULL){
        return -1;
    }

    ListNode *cursor = head;
    int len = 0;
    while(cursor != NULL){
        len++;
        cursor = cursor->next;
    }

    cursor = head;
    int count = len - k + 1;
    while(count > 1){
        count--;
        cursor = cursor->next;
    }

    return cursor->val;
}

/**
 * Two pointer solution
 * Time:  O(n)
 * Space: O(1)
 */
int twoPointer(ListNode *head, int k){

    if(head == NULL){
        return -1;
    }

    ListNode *fast = head;
    ListNode *slow = head;
    int count = 0;
    while(fast != NULL){
        if(count >= k){
            slow = slow->next;
            fast = fast->next;
        }
        else{
            count++;
            fast = fast->next;
        }
    }

    return slow->val;
}


/**
 * Main function
 * normal case, edge case.
 */
int main(){

    ListNode *one = NULL;

    cout << "NAIVE 1st: " << naive(one, 1) << endl;
    one = NULL;
    cout << "TP    1st: " << twoPointer(one, 1) << endl;

    ListNode *two   = new ListNode(1);
    ListNode *three = new ListNode(2);
    two->next       = three;
    ListNode *four  = new ListNode(3);
    three->next     = four;
    ListNode *five  = new ListNode(4);
    four->next      = five;
    cout << "NAIVE 1st: " << naive(two, 1) << endl;
    cout << "TP    1st: " << twoPointer(two, 1) << endl;
    cout << "NAIVE 4st: " << naive(two, 4) << endl;
    cout << "TP    4st: " << twoPointer(two, 4) << endl;
    cout << "NAIVE 3st: " << naive(two, 3) << endl;
    cout << "TP    3st: " << twoPointer(two, 3) << endl;
 
    return 0;
}
