//
// Created by Air on 2023/3/1.
//
// https://leetcode.cn/problems/stack-of-plates-lcci/

#include "stack"
#include "vector"
#include "iostream"
using namespace std;

class StackOfPlates {
private:
    vector<stack<int>> plates_es;
    int capacity;
public:
    StackOfPlates(int cap) { // capacity 每个栈的最大容量
        capacity = cap;
    }

    void push(int val) {
        // 没有盘堆或者最后一个盘堆满了，则需要重起一个盘堆并将新盘子放进去
        //if (plates_es.empty() || full(plates_es.back())) {
        //    stack<int> plates;
        //    plates.push(val);
        //    plates_es.push_back(plates);
        //} else {
        //    plates_es.back().push(val);
        //}
        if (capacity == 0) {
            // 如果capacity为0，直接return
            return;
        }
        if (plates_es.empty() || plates_es.back().size() == capacity) {
            // 当前vector为空或当前栈满，新增一个栈
            plates_es.emplace_back(stack<int>());
        }
        plates_es.back().push(val);

    }

    int pop() {
        if (plates_es.empty())
            return -1;
        int top = plates_es.back().top();
        plates_es.back().pop();
        if (plates_es.back().empty())
            plates_es.pop_back();
        return top;
    }

    int popAt(int index) {
        if (index >= plates_es.size() || plates_es[index].empty())
            return -1;
        int top =  plates_es[index].top();
        plates_es[index].pop();
        if (plates_es[index].empty())
            plates_es.erase(plates_es.begin()+index);

        return top;
    }

    bool full(stack<int> plates) {
        return plates.size() == capacity;
    }

    void print() {
        vector<stack<int>> plates_es_copy(plates_es);
        for (auto plates : plates_es_copy) {
            while (!plates.empty()) {
                cout << plates.top() << " ";
                plates.pop();
            }
            cout << endl;
        }
    }
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */


int main() {
    int cap(2), val(1), index(1);
    StackOfPlates* obj = new StackOfPlates(cap);
    for (int i = 0; i < 5; ++i) {
        obj->push(val + i);
    }
    obj->print();
    cout << obj->pop() << endl;
    cout << obj->popAt(index + 1) << endl;
    obj->print();
    return 0;
}