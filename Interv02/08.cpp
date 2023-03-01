//
// Created by Air on 2023/2/28.
//
// https://leetcode.cn/problems/linked-list-cycle-lcci/
#include "LinkList.h"
#include "stack"
#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    // 假设：环路初始节点为X，快慢指针相交节点为Y
    // 规律：从Y到X的距离与从head到X距离相同
    // 思路：先找快慢指针相交节点，再从head和该节点开始同时走，相遇即为所求
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast(head), *slow(head);
        int pos(0);
        do {
            if (!fast || !fast->next || !fast->next->next) {
                pos = -1;
                break;
            }
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);
        if (pos == -1)
            return nullptr;
        slow = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};

int main() {
    LinkList L;
    vector<int> arr = {1 };//, 2, 3, 4, 5, 6};
    for (int item : arr)
        L.push_back(item);
    cout << L.to_string() << endl;
    L.create_circle(0);

    Solution test;
    cout << test.detectCycle(L.get_head())->val;
    return 0;
}