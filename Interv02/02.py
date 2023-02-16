# https://leetcode.cn/problems/kth-node-from-end-of-list-lcci/comments/

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
    def kthToLast(self, head: ListNode, k: int) -> int:
        fast, low = head, head
        for i in range(k):
            fast = fast.next
        if fast:
            while fast.next:
                fast, low = fast.next, low.next
            print(low.next.val)
            return low.next.val
        else:
            print(low.val)
            return low.val


if __name__ == '__main__':
    demo = LinkList()
    for i in range(1, 16):
        demo.append(i)
    print(demo)
    test = Solution()
    test.kthToLast(demo.get_head(), k=1)
