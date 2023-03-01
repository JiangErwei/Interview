//
// Created by Air on 2023/2/28.
//
// https://leetcode.cn/problems/three-in-one-lcci/

#include "iostream"
using namespace std;

class TripleInOne {
private:
    int stackSize;
    int* stacks;
    int size[3] = {0, 0, 0};
public:
    // 初始位置索引分别为：0，stackSize，2*stackSize
    TripleInOne(int stackSize) {
        stacks = new int[stackSize*3];
        this->stackSize = stackSize;
    }

    void push(int stackNum, int value) {
        if (size[stackNum] < stackSize) {
            stacks[stackNum * stackSize + size[stackNum]] = value;
            size[stackNum]++;
        }
    }

    int pop(int stackNum) {
        if (isEmpty(stackNum))
            return -1;
        int top = stacks[stackNum * stackSize + size[stackNum] - 1];
        size[stackNum]--;
        return top;
    }
    // 栈顶元素位置分别为：0+size[0]-1，stackSize+size[1]-1，2*stackSize+size[2]-1
    int peek(int stackNum) {
        if (isEmpty(stackNum))
            return -1;
        return stacks[stackNum * stackSize + size[stackNum] - 1];
    }

    bool isEmpty(int stackNum) {
        return size[stackNum] == 0;
    }

    void print() {
        for (int i = 0; i < stackSize * 3; ++i) {
            cout << stacks[i] << " ";
        }
        cout << endl;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */

int main() {
    TripleInOne test(3);
    test.print();
    for (int i = 1; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            test.push(j, i);
            test.print();
        }
    }
    cout << endl;
    for (int i = 1; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << test.pop(j) << " -> ";
            test.print();
        }
    }

    return 0;
}