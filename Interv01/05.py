# https://leetcode.cn/problems/one-away-lcci/?favorite=xb9lfcwi

class Solution:
    def oneEditAway(self, first: str, second: str) -> bool:
        if abs(len(first) - len(second)) > 1:
            return False
        if first == second:
            return True
        # 思路：双指针法 - 前后双指针寻找字符不匹配位置，若位置不同则不对
        if len(first) < len(second):
            first, second = second, first
        if second == "":
            return True
        start, end = 0, -1

        while start < len(second) and first[start] == second[start]:
            start += 1
        while abs(end) <= len(second) and first[end] == second[end]:
            end -= 1

        if start == len(first) + end:
            return True
        else:
            return False

if __name__ == '__main__':
    test = Solution()
    first = "b"
    second = "ab"
    print(test.oneEditAway(first, second))




