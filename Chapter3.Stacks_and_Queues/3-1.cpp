/**
 * Chapter 3  --  3.1
 * Describe how you could use a single array to implement three stacks.
 */

/**
 * Author: Teddy
 * Date: 28-01-2015 
 */

/**
 * Analysis:
 * 1. Static size solution: Each stack with a static size, split the array into 
 *                          three part. Using an int array to store the indices.
 * 2. Dynamic size solution: 
 */ 

#include <iostream>

#define STACK_SIZE 100
#define STACK_NUMBER 3

using namespace std;

/**
 * Static size stacks.
 */
class staticStack {
private:
    int array[STACK_SIZE * STACK_NUMBER];
    int indices[STACK_NUMBER];
public:
    staticStack(){
        // init indices
        for(int i = 0; i < STACK_NUMBER; i++){
            indices[i] = STACK_SIZE * i;
        }
    }
    ~staticStack(){

    }

    void push(int index, int value){
        if(index < 0 || index >= STACK_NUMBER ||
           indices[index] >= STACK_SIZE * (index + 1)){
            return;
        }
        array[indices[index]] = value;
        indices[index]++;
    }
    
    int top(int index){
        if(index < 0 || index >= STACK_NUMBER ||
           indices[index] <= STACK_SIZE * index){
            return 0;
        }
        return array[indices[index] - 1];
    }
    
    void pop(int index){
        if(index < 0 || index >= STACK_NUMBER ||
           indices[index] <= STACK_SIZE * index){
            return;
        }
        indices[index]--;
    }
    
    int size(int index){
        if(index < 0 || index >= STACK_NUMBER){
            return 0;
        }
        return indices[index] - STACK_SIZE * index;
    }
};

/**
 * Main function
 * normal case, edge case.
 */
int main(){

    // static stack
    cout << "---STATIC STACK---" << endl;
    staticStack ss;
    cout << "Push 1 to stack 1 ..." << endl;
    ss.push(0, 1);
    cout << "Push 2 to stack 2 ..." << endl;
    ss.push(1, 2);
    cout << "Push 3 to stack 3 ..." << endl;
    ss.push(2, 3);
    cout << "Get size of stack 1: " << ss.size(0) << endl;
    cout << "Get top  of stack 1: " << ss.top(0) << endl;
    cout << "Get size of stack 2: " << ss.size(1) << endl;
    cout << "Get top  of stack 2: " << ss.top(1) << endl;
    cout << "Get size of stack 3: " << ss.size(2) << endl;
    cout << "Get top  of stack 3: " << ss.top(2) << endl;
    cout << "Pop from stack 1 ..." << endl;
    ss.pop(0);
    cout << "Pop from stack 2 ..." << endl;
    ss.pop(1);
    cout << "Pop from stack 3 ..." << endl;
    ss.pop(2);
    cout << "Get size of stack 1: " << ss.size(0) << endl;
    cout << "Get top  of stack 1: " << ss.top(0) << endl;
    cout << "Get size of stack 2: " << ss.size(1) << endl;
    cout << "Get top  of stack 2: " << ss.top(1) << endl;
    cout << "Get size of stack 3: " << ss.size(2) << endl;
    cout << "Get top  of stack 3: " << ss.top(2) << endl;
 
    return 0;
}
