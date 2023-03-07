//
// Created by Air on 2023/3/6.
//
// https://leetcode.cn/problems/list-of-depth-lcci/

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

#include "LinkTree.h"
#include "queue"

class Solution {
public:
    // copy by 02.cpp
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
            return nullptr;
        int mid(nums.size() / 2);
        TreeNode *head = new TreeNode(nums[mid]);
        vector<int> smalls(nums.begin(), nums.begin() + mid);
        vector<int> bigs(nums.begin() + mid + 1, nums.end());
        head->left = sortedArrayToBST(smalls);
        head->right = sortedArrayToBST(bigs);
        return head;
    }
    // 实际上就是层序输出
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        if (!tree)
            return vector<ListNode*>();
        queue<TreeNode*> que;
        que.push(tree);
        vector<ListNode*> lay;
        ListNode *head, *cur;
        while (!que.empty()) {
            // 设置计数器，用于记录下一次要出队几个元素
            int  n = que.size();
            head = new ListNode(-1);
            cur = head;
            // 将当前n个元素串串，并push到结果集里
            // 将当前n个元素出队，并将其子节点入队
            for (int i = 0; i < n; ++i) {
                if (que.front()->left)
                    que.push(que.front()->left);
                if (que.front()->right)
                    que.push(que.front()->right);
                cur->next = new ListNode(que.front()->val);
                cur = cur->next;
                que.pop();
            }
            lay.push_back(head->next);
        }
        return lay;
    }
};

int main() {
    Solution test;
    vector<int> nums = {-10,-3,0,5,9};
    auto head = test.sortedArrayToBST(nums);
    auto vec = test.listOfDepth(head);
    for (auto list : vec) {
        while (list) {
            cout << list->val;
            if (list->next)
                cout << " -> ";
            list = list->next;
        }
        cout << endl;
    }
    return 0;
}