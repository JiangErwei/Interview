//
// Created by Air on 2023/3/1.
//
// https://leetcode.cn/problems/implement-queue-using-stacks-lcci/

#include "iostream"
#include "stack"
using namespace std;

class MyQueue {
private:
    // 两个栈，一个用来存储元素，一个用来进行操作转换
    stack<int> store, opera;
    int size;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        size = 0;
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        store.push(x);
        ++size;
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (opera.empty())
            while (!store.empty()) {
                opera.push(store.top());
                store.pop();
            }
        int top(opera.top());
        opera.pop();
        --size;
        return top;
    }

    /** Get the front element. */
    int peek() {
        if (opera.empty())
            while (!store.empty()) {
                opera.push(store.top());
                store.pop();
            }
        return opera.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return size == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {

    MyQueue queue = *new MyQueue();

    queue.push(1);
    queue.push(2);
    cout << queue.peek() << endl;  // 返回 1
    cout << queue.pop() << endl;   // 返回 1
    cout << queue.empty(); // 返回 false

    return 0;
}