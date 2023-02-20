# https://leetcode.cn/problems/partition-list-lcci/

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
    def partition(self, head: ListNode, x: int) -> ListNode:
        smalls = ListNode(-1)
        bigs = ListNode(-1)
        p, q = smalls, bigs

        cur = head
        while cur:
            if cur.val < x:
                p.next = cur
                p = p.next
            else:
                q.next = cur
                q = q.next
            cur = cur.next

        p.next = bigs.next
        q.next = None
        return smalls.next


if __name__ == '__main__':
    demo = LinkList()
    arr = [1, 4, 3, 2, 5, 2]
    # arr = [2, 1, 3]
    for item in arr:
        demo.append(item)
    print(demo)
    test = Solution()
    test.partition(demo.get_head(), 3)
    print(demo)