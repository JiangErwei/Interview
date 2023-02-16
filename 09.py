# https://leetcode.cn/problems/string-rotation-lcci/

class Solution:
    def isFlipedString(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
        length = len(s1)
        p1, q1 = 0, 0
        p2, q2 = 0, 0
        # 第一次寻找相同子串
        for i in range(length):
            if s1[p1] != s2[p2]:
                p2 += 1
            else:
                q1 = p1 + 1
                q2 = p2 + 1
                while q2 < length:
                    if s1[q1] == s2[q2]:
                        q1 += 1
                        q2 += 1
                    else:
                        break
                if q2 < length:
                    p2 += 1
        # print(s1[p1: q1], s2[p2: q2])
        p1, q1 = q1, length
        q2 = 0
        # print(s1[p1: q1], s2[q2: p2])
        # 余下子串比较
        return True if s1[p1: q1] == s2[q2: p2] else False


if __name__ == '__main__':
    test = Solution()
    s1 = "erbottlewat"
    s2 = "terbottlewa"
    print(test.isFlipedString(s1, s2))
