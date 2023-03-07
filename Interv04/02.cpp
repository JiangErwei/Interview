//
// Created by Air on 2023/3/6.
//
// https://leetcode.cn/problems/minimum-height-tree-lcci/

#include "LinkTree.h"
#include "queue"
#include "math.h"

class Solution {
public:
    // 算法思想，给定的是一个有序数组，就按照二分思想分别取数，有递归和非递归实现
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

    // 按层序打印输出二叉树
        void print(TreeNode* head) {
            if (!head)
                return;
            queue<TreeNode*> q;
            q.push(head);
            while (!q.empty()) {
                int size = q.size();
                for (int i = 0; i < size; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    cout << node->val << " ";
                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                }
                cout << endl;
            }
        }
};


int main() {
    Solution test;
    vector<int> nums = {-10,-3,0,5,9};
    test.print(test.sortedArrayToBST(nums));

    return 0;
}