# https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/

# Definition for singly-linked list.
from typing import Tuple, Union, Any


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class LinkList:
    def __init__(self):
        self.__head = None
        self.__length = 0

    def __repr__(self):
        cur = self.__head
        lis = []
        for i in range(self.__length):
            lis.append(str(cur.val))
            cur = cur.next
        return " -> ".join(lis)

    def append(self, item):
        node = ListNode(item)
        if self.__length == 0:
            self.__head = node
        else:
            cur = self.__head
            while cur.next:
                cur = cur.next
            cur.next = node
        self.__length += 1

    def get_head(self):
        return self.__head

    def update_length(self):
        self.__length = 0
        cur = self.__head
        while cur:
            self.__length += 1
            cur = cur.next


class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        lenA, lenB = 0, 0
        curA, curB = headA, headB
        while curA or curB:
            if curA:
                lenA += 1
                curA = curA.next
            if curB:
                lenB += 1
                curB = curB.next
        curA, curB = headA, headB
        if lenA > lenB:
            for i in range(lenA - lenB):
                curA = curA.next
        elif lenB > lenA:
            for i in range(lenB - lenA):
                curB = curB.next
        while curA != curB and curA and curB:
            curA, curB = curA.next, curB.next
        return curA

    def Merge(self, headA: ListNode, headB: ListNode, headC:ListNode) -> tuple[
        Union[ListNode, Any], Union[ListNode, Any]]:
        A, B = headA, headB
        while headA.next:
            headA = headA.next
        while headB.next:
            headB = headB.next
        headA.next = headC
        headB.next = headC
        return A, B


if __name__ == '__main__':
    l1, l2, l3 = LinkList(), LinkList(), LinkList()
    arr1 = [4, 1]
    arr2 = [5, 0, 1]
    arr3 = [10, 2, 3]
    for item in arr1:
        l1.append(item)
    for item in arr2:
        l2.append(item)
    for item in arr3:
        l3.append(item)

    test = Solution()
    A, B = test.Merge(l1.get_head(), l2.get_head(), l3.get_head())
    print(test.getIntersectionNode(A, B).val)

