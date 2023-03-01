//
// Created by Air on 2023/2/28.
//
// https://leetcode.cn/problems/palindrome-linked-list-lcci/

#include "LinkList.h"
#include "stack"
#include "iostream"
#include "vector"

class Solution {
public:
    // 采用栈解决
    bool isPalindrome(ListNode* head) {
        int length(0);
        ListNode* cur(head);
        while (cur) {
            ++length;
            cur = cur->next;
        }

        stack<int> s;
        cur = head;
        for (int i = 0; i < length / 2; ++i) {
            s.push(cur->val);
            cur = cur->next;
        }
        if (length % 2)
            cur = cur->next;
        bool flag(true);
        for (int i = 0; i < length / 2; ++i) {
            if (s.top() != cur->val) {
                flag = false;
                break;
            }
            s.pop();
            cur = cur->next;
        }
        return flag;
    }
};


int main() {
    LinkList L;
    vector<int> arr = {1, 4, 3, 3, 4, 1};
    for (int item : arr)
        L.push_back(item);
    cout << L.to_string() << endl;

    Solution test;
    cout << test.isPalindrome(L.get_head());
    return 0;
}