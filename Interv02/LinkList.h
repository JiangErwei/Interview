//
// Created by Air on 2023/2/27.
//

#ifndef INTERVIEW_LINKLIST_H
#define INTERVIEW_LINKLIST_H
#include "string"
using namespace std;


typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}ListNode;

class LinkList {
private:
    int length;
    ListNode *head;
public:
    LinkList() { // 构造函数
        length = 0;
        head = new ListNode(length);
        head->next = nullptr;
    }
    int size() { // 获取长度
        return length;
    }
    ListNode* get_head() { // 获取头节点指针
        return head->next;
    }
    bool empty() { // 判断是否非空
        return length == 0;
    }
    void push_back(int val) { // 尾插元素
        ListNode* cur(head);
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = new ListNode(val);
        length++;
    }
    string to_string() {
        string s("");
        ListNode* cur(head->next);
        while (cur->next) {
            s += std::to_string(cur->val);
            s += " -> ";
            cur = cur->next;
        }
        s += std::to_string(cur->val);
        return s;
    }
    void update_size() {
        ListNode *cur = head->next;
        length = 0;
        while (cur) {
            ++length;
            cur = cur->next;
        }
    }
    void create_circle(int pos) { // 构造环路
        auto tail = head->next;
        auto cur = head->next;
        while (tail->next)
            tail = tail->next;
        for (int i = 0; i < pos; ++i)
            cur = cur->next;
        tail->next = cur;
    }
};


#endif //INTERVIEW_LINKLIST_H
