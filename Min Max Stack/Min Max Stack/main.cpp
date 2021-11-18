//
//  main.cpp
//  Min Max Stack
//
//  Created by Jose Mari Syjuco on 18/11/21.
//
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class MinMaxStack {
public:
    int size() const;   // Time: O(1) | Space: O(1)
    bool empty() const; // Time: O(1) | Space: O(1)
    int top() const;    // Time: O(1) | Space: O(1)
    void push(int e);   // Time: O(1) | Space: O(1)
    int pop();          // Time: O(1) | Space: O(1)
    int getMin() const; // Time: O(1) | Space: O(1)
    int getMax() const; // Time: O(1) | Space: O(1)
private:
    vector<int> stack;
    vector<unordered_map<string, int>> minMaxStack;
};

int MinMaxStack::size() const { return (int)stack.size(); }
bool MinMaxStack::empty() const { return size() == 0; }
int MinMaxStack::top() const { return empty() ? -1 : stack[size() - 1]; }
void MinMaxStack::push(int number) {
    unordered_map<string, int> newRecord;
    
    if (empty()) {
        newRecord.insert({"min", number});
        newRecord.insert({"max", number});
    } else {
        unordered_map<string, int> lastRecord = minMaxStack[size() - 1];
        newRecord.insert({ "min", min(number, lastRecord["min"]) });
        newRecord.insert({ "max", max(number, lastRecord["max"]) });
    }
    
    stack.push_back(number);
    minMaxStack.push_back(newRecord);
}
int MinMaxStack::pop() {
    if (empty()) return -1;
    
    int top = stack[size() - 1];
    stack.pop_back();
    minMaxStack.pop_back();
    return top;
}

int MinMaxStack::getMin() const {
    if (empty()) return -1;
    
    unordered_map<string, int> lastRecord = minMaxStack[size() - 1];
    return lastRecord["min"];
}

int MinMaxStack::getMax() const {
    if (empty()) return -1;
    
    unordered_map<string, int> lastRecord = minMaxStack[size() - 1];
    return lastRecord["max"];
}

int main() {
    MinMaxStack *stack = new MinMaxStack();
    printf("Add 15\n");
    stack->push(15);
    printf("Top: %d\n", stack->top());
    printf("Min: %d | Max: %d\n", stack->getMin(), stack->getMax());
    printf("Add 7\n");
    stack->push(7);
    printf("Min: %d | Max: %d\n", stack->getMin(), stack->getMax());
    printf("Add 12\n");
    stack->push(12);
    printf("Min: %d | Max: %d\n", stack->getMin(), stack->getMax());
    printf("Pop: %d\n", stack->pop());
    printf("Pop: %d\n", stack->pop());
    printf("Min: %d | Max: %d\n", stack->getMin(), stack->getMax());
    printf("Add 4\n");
    stack->push(4);
    printf("Min: %d | Max: %d\n", stack->getMin(), stack->getMax());
    printf("Add 23\n");
    stack->push(23);
    printf("Min: %d | Max: %d\n", stack->getMin(), stack->getMax());
    printf("Pop: %d\n", stack->pop());
    printf("Top: %d\n", stack->top());
    printf("Add 1\n");
    stack->push(1);
    printf("Min: %d | Max: %d\n", stack->getMin(), stack->getMax());
    return 0;
}
