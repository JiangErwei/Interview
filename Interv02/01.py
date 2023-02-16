# https://leetcode.cn/problems/remove-duplicate-node-lcci/

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
    def removeDuplicateNodes(self, head: ListNode) -> ListNode:
        if not head:
            return head
        pre, cur = head, head.next
        Hash = set()
        Hash.add(head.val)
        while pre.next:
            if cur.val not in Hash:
                Hash.add(cur.val)
                pre, cur = pre.next, cur.next
            else:
                pre.next = cur.next
                del cur
                cur = pre.next
        return head


if __name__ == '__main__':
    arr = [1, 1, 1, 1, 2]
    demo = LinkList()
    for elem in arr:
        demo.append(elem)
    print(demo)
    test = Solution()
    test.removeDuplicateNodes(demo.get_head())
    demo.update_length()
    print(demo)