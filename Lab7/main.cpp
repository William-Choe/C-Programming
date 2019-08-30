#include <iostream>
#include "stack.hpp"

int main() {
    //initializing a stack
    NEU::stack<int> stack;

    //adding data
    stack.push(13);
    stack.push(18);
    stack.push(78);
    stack.push(23);
    stack.push(56);

    //duplicate a stack (deep copy)
    NEU::stack<int> stack_dup(stack);

    //test function
    cout << stack;
    cout << ">> Test size(): " << stack.size() << endl;
    cout << ">> Test peek(): " << stack.peek() << endl;

    if (!stack.empty()) {
        stack.pop();
        cout << ">> Test pop(): " << stack;
    }

    //test duplication
    cout << ">> Test duplication: " << stack_dup;

    return 0;
}