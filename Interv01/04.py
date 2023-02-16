# https://leetcode.cn/problems/palindrome-permutation-lcci/

class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        # 思路：对出现的字符进行频次统计，出现两个奇数频数字符，就错了
        count_s = dict()
        for c in s:
            count_s[c] = 0
        for c in s:
            count_s[c] += 1

        cnt = 0
        for i in count_s.values():
            if i % 2 == 1:
                cnt += 1

        if cnt > 1:
            return False
        else:
            return True

if __name__ == '__main__':
    test = Solution()
    print(test.canPermutePalindrome("code"))
