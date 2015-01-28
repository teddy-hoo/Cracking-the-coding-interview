/**
 * Chapter 3  --  3.2
 * How would you design a stack which, inaddition to push and pop, also has a
 * function min which returns the minimum element? Push, pop and min should all
 * operate in O(1) time.
 */

/**
 * Author: Teddy
 * Date: 28-01-2015 
 */

/**
 * Analysis:
 * Using another stack cache the mins of current stack.
 */ 

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;
public:
    MinStack(){

    }
    ~MinStack(){

    }

    void push(int value){
        mainStack.push(value);
        if(minStack.empty() || minStack.top() >= value){
            minStack.push(value);
        }
    }
    
    void pop(){
        if(mainStack.empty()){
            return;
        }
        int value = mainStack.top();
        mainStack.pop();
        if(value == minStack.top()){
            minStack.pop();
        }
    }
    int min(){
        if(minStack.empty()){
            return 0;
        }
        return minStack.top();
    }
};

/**
 * Main function
 * normal case, edge case.
 */
int main(){

    int numbers[10] = {5, 6, 4, 3, 7, 8, 1, 9, 1, 1};

    MinStack ms;
    cout << "----PUSH----" << endl;
    for(int i = 0; i < 10; i++){
        cout << "Push " << numbers[i] << " to ms ..." << endl;
        ms.push(numbers[i]);
        cout << "Current min in ms: " << ms.min() << endl;
    }
    cout << endl;

    cout << "----POP----" << endl;
    for(int i = 0; i < 11; i++){
        cout << "Pop ms ..." << endl;
        ms.pop();
        cout << "Current min in ms: " << ms.min() << endl;
    }

    return 0;
}
