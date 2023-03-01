//
// Created by Air on 2023/2/28.
//
// https://leetcode.cn/problems/kth-node-from-end-of-list-lcci/


#include "iostream"
#include "LinkList.h"
#include "vector"
using namespace std;

class Solution {
public:
    // 快慢指针法
    int kthToLast(ListNode* head, int k) {
        auto fast(head), low(head);
        // 快指针先走k步
        for (int i = 0; i < k; ++i)
            fast = fast->next;
        // 两个指针一起走，直到fast走到尾
        while (fast) {
            fast = fast->next;
            low = low->next;
        }
        return low->val;
    }
};


int main() {
    LinkList L;
    vector<int> arr = {1}; //, 2, 3, 4, 5, 6};
    for (int item : arr)
        L.push_back(item);
    cout << L.to_string() << endl;

    Solution test;
    cout << test.kthToLast(L.get_head(), 1);
    return 0;
}