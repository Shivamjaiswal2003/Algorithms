#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Stack {
  int size;
  vector<int> arr;
  int top;
public:
  Stack() {
    top = -1;
    size = 1000;
    arr.resize(size);
  }

  void push(int x) {
    if (top >= size - 1) {
      cout << "Stack Overflow" << endl;
      return;
    }
    top++;
    arr[top] = x;
  }

  int pop() {
    if (top < 0) {
      cout << "Stack Underflow" << endl;
      return -1; // Return a sentinel value to indicate failure
    }
    int x = arr[top];
    top--;
    return x;
  }

  int Top() {
    if (top < 0) {
      cout << "Stack Underflow" << endl;
      return -1; // Return a sentinel value to indicate failure
    }
    return arr[top];
  }

  int Size() {
    return top + 1;
  }
};

int main() {
    Stack myStack;

    cout << "Pushing 10 onto the stack." << endl;
    myStack.push(10);
    cout << "Current size: " << myStack.Size() << endl;

    cout << "Popped: " << myStack.pop() << endl;
    cout << "Current size: " << myStack.Size() << endl;
    
    // This next line will trigger the underflow error message
    cout << "Attempting to pop from an empty stack..." << endl;
    myStack.pop(); 

    // Example of a stack overflow
    cout << "\nAttempting to cause a stack overflow..." << endl;
    for (int i = 0; i < 1001; ++i) {
        myStack.push(i);
    }
    
    cout << "Final stack size: " << myStack.Size() << endl;

    return 0;
}