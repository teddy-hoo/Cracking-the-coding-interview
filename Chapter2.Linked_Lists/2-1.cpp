/**
 * Chapter 2  --  2.1
 * Write code to remove duplicates from an unsorted linked list.
 */

/**
 * Author: Teddy
 * Date: 27-01-2015 
 */

/**
 * Analysis:
 * 1. Naive solution: check previous node, use O(n^2) time.
 * 2. Cache solution: use hash as a cache, O(n) time.
 */ 

#include <iostream>
#include <unordered_set>

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
 * Time:  O(n^2)
 * Space: O(1)
 */
void naive(ListNode *head){
    
    if(head == NULL){
        return;
    }

    ListNode *cur = head->next;
    ListNode *pre = head;

    while(cur != NULL){
        ListNode *cursor = head;
        bool duplicated = false;
        while(cursor != cur){
            if(cursor->val == cur->val){
                duplicated = true;
                break;
            }
            cursor = cursor->next;
        }
        if(duplicated){
            pre->next = cur->next;
            free(cur);
            cur = pre->next;
        }
        else{
            pre = pre->next;
            cur = cur->next;
        }
    }
}

/**
 * Cache solution
 * Time:  O(n)
 * Space: O(n)
 */
void cache(ListNode *head){

    if(head == NULL){
        return;
    }

    unordered_set<int> cache;
    ListNode *pre;
    ListNode *cur = head;
    while(cur != NULL){
        if(cache.count(cur->val) > 0){
            pre->next = cur->next;
            free(cur);
            cur = pre->next;
        }
        else{
            cache.insert(cur->val);
            pre = cur;
            cur = cur->next;
        }
    }
}

void printList(ListNode *head){
    while(head != NULL){
        cout << head->val << " ";
        head = head->next; 
    }
    cout << endl;
}

/**
 * Main function
 * normal case, edge case.
 */
int main(){

    ListNode *one = NULL;
    naive(one);
    printList(one);
    one = NULL;
    cache(one);
    printList(one);

    ListNode *two   = new ListNode(1);
    ListNode *three = new ListNode(2);
    two->next       = three;
    ListNode *four  = new ListNode(1);
    three->next     = four;
    ListNode *five  = new ListNode(2);
    four->next      = five;
    naive(two);
    printList(two);

    two         = new ListNode(1);
    three       = new ListNode(2);
    two->next   = three;
    four        = new ListNode(1);
    three->next = four;
    five        = new ListNode(2);
    four->next  = five;
    cache(two);
    printList(two);

    return 0;
}