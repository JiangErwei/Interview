# https://leetcode.cn/problems/delete-middle-node-lcci/?favorite=xb9lfcwi

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
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        p = node.next
        node.val = p.val
        node.next = p.next
        del p


if __name__ == '__main__':
    demo = LinkList()
    for i in range(10):
        demo.append(i)
    print(demo)
    node = demo.get_head()
    for j in range(8):
        node = node.next
    print(node.val)
    test = Solution()
    test.deleteNode(node)
    demo.update_length()
    print(demo)

