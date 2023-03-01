//
// Created by Air on 2023/2/28.
//
// https://leetcode.cn/problems/min-stack-lcci/
#include "stack"
using namespace std;

class MinStack {
private:
    stack<int> elem_stack;  // 存储正常读写元素
    stack<int> min_stack;   // 仅存储一次操作之后的最小值
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        elem_stack.push(x);
        min_stack.push(min(x, min_stack.top()));
    }

    void pop() {
        elem_stack.pop();
        min_stack.pop();
    }

    int top() {
        return elem_stack.top();
    }

    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
