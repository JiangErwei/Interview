//
// Created by Air on 2023/2/28.
//
// https://leetcode.cn/problems/partition-list-lcci/
#include "iostream"
#include "LinkList.h"
#include "vector"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* big = new ListNode(-1);
        ListNode* small = new ListNode(-1);
        auto b(big), s(small);
        auto cur(head);
        while (cur) {
            if (cur->val < x) {
                s->next = cur;
                s = s->next;
            } else {
                b->next = cur;
                b = b->next;
            }
            cur = cur->next;
        }
        s->next = big->next;
        b->next = nullptr;
        head = small->next;
        return head;
    }
};

int main() {
    LinkList L;
    vector<int> arr = {1, 4, 3, 2, 5, 2};
    for (int item : arr)
        L.push_back(item);
    cout << L.to_string() << endl;

    Solution test;
    test.partition(L.get_head(), 3);
    cout << L.to_string();
    return 0;
}