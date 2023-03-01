//
// Created by Air on 2023/2/27.
//
// https://leetcode.cn/problems/remove-duplicate-node-lcci/

#include "LinkList.h"
#include "iostream"
#include "vector"
#include "unordered_set"
using namespace std;

class Solution {
public:
    // hash策略
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (!head)
            return nullptr;

        unordered_set<int> Set;
        ListNode *pre(head), *cur(head->next);
        Set.insert(head->val);
        while (pre->next) {
            if (Set.find(cur->val) == Set.end()) {
                Set.insert(cur->val);
                pre = pre->next;
                cur = cur->next;
            }
            else {
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            }
        }
        return head;
    }
};

int main() {
    LinkList L;
    vector<int> arr = {1, 2, 3, 3, 2, 1};
    for (int item : arr)
        L.push_back(item);
    cout << L.to_string() << endl;

    Solution test;
    test.removeDuplicateNodes(L.get_head());
    L.update_size();
    cout << L.to_string() << endl;

    return 0;
}