# https://leetcode.cn/problems/check-permutation-lcci/?favorite=xb9lfcwi

class Solution:
    # 思路一：遍历s1，并在每次遍历时，在s2中删除当前字符，如果最后s2为空即正确
    # 时间复杂度n^2

    # 思路二：对两个字符串进行排序，之后逐一对比，如有不同则不正确
    # 时间复杂度：取决于使用的排序方法
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False

        list_s1 = sorted(s1)
        list_s2 = sorted(s2)

        flag = True
        for i in range(len(s1)):
            if list_s1[i] != list_s2[i]:
                flag = False
                break
        return flag


    # 思路三：哈希策略
    # 时间复杂度n
    def CheckPermutation_1(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False

        hash_dic = dict()
        for i in range(ord('a'), ord('a') + 26):
            hash_dic[chr(i)] = 0

        for s in s1:
            hash_dic[s] += 1

        for s in s2:
            hash_dic[s] -= 1

        if max(hash_dic.values()) > 0 or min(hash_dic.values()) < 0:
            return False
        else:
            return True
        # 执行用时：high
        # 内存消耗：low


if __name__ == '__main__':
    test = Solution()
    s1 = "abc"
    s2 = "bad"
    print(test.CheckPermutation(s1, s2))
