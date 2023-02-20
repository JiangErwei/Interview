# https://leetcode.cn/problems/sum-lists-lcci/

# Definition for singly-linked list.

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
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) : # -> ListNode:
        len1, len2 = 0, 0
        num1, num2 = 0, 0
        cur = l1
        while cur:
            num1 += cur.val * (10**len1)
            len1 += 1
            cur = cur.next
        cur = l2
        while cur:
            num2 += cur.val * (10**len2)
            len2 += 1
            cur = cur.next
        res = ListNode(-1)
        cur = res
        num = num1 + num2
        while num:
            cur.next = ListNode(num % 10)
            num //= 10
            cur = cur.next
        return res.next if res.next else ListNode(0)


if __name__ == '__main__':
    l1 = LinkList()
    l2 = LinkList()

    arr1 = [7, 1, 6]
    arr2 = [5, 9, 2]

    for item in arr1:
        l1.append(item)
    for item in arr2:
        l2.append(item)

    print(l1)
    print(l2)
    test = Solution()
    test.addTwoNumbers(l1.get_head(), l2.get_head())
