# https://leetcode.cn/problems/palindrome-linked-list-lcci/

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
    def isPalindrome(self, head: ListNode) -> bool:
        cur = head
        length = 0
        while cur:
            length += 1
            cur = cur.next
        fast, low = head, head
        length = length // 2 if length % 2 == 0 else length // 2 + 1
        for i in range(length):
            fast = fast.next
        before, after = [], []
        while fast:
            before.append(low.val)
            after.append(fast.val)
            fast, low = fast.next, low.next
        return before == after[::-1]


if __name__ == '__main__':
    l = LinkList()
    arr = [1, 4, -1, -1, 4, 1]
    for item in arr:
        l.append(item)
    print(l)
    test = Solution()
    print(test.isPalindrome(l.get_head()))
