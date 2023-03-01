//
// Created by Air on 2023/3/1.
//
// https://leetcode.cn/problems/sort-of-stacks-lcci/

#include "iostream"
#include "stack"
using namespace std;

class SortedStack {
private:
    stack<int> stack_main, stack_tmp;
public:
    SortedStack() {
    }

    void push(int val) {
        while (!stack_main.empty() && val > stack_main.top()) {
            stack_tmp.push(stack_main.top());
            stack_main.pop();
        }
        stack_main.push(val);
        while (!stack_tmp.empty()) {
            stack_main.push(stack_tmp.top());
            stack_tmp.pop();
        }
    }

    void pop() {
        if (!stack_main.empty())
            stack_main.pop();
    }

    int peek() {
        if (stack_main.empty())
            return -1;
        return stack_main.top();
    }

    bool isEmpty() {
        return stack_main.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */

int main() {
    SortedStack* obj = new SortedStack();
    obj->pop();
    obj->push(1);
    obj->push(2);
    cout << obj->peek() << endl;
    obj->pop();
    cout << obj->peek() << endl;
    cout << obj->isEmpty();
    return 0;
}
