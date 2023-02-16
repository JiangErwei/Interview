# https://leetcode.cn/problems/is-unique-lcci/?favorite=xb9lfcwi

class Solution:
    def isUnique_1(self, astr: str) -> bool:
        # 直接用字典进行去重即可
        set_s = set(astr)
        if len(set_s) < len(astr):
            return False
        else:
            return True


    def isUnique(self, astr: str) -> bool:
        """
        限制：
        0 <= len(s) <= 100
        s[i]仅包含小写字母
        如果你不使用额外的数据结构，会很加分。

        :param astr: str
        :return: bool
        """
        # 哈希表策略
        hash_dic = dict()
        for i in range(ord('a'), ord('a')+26):
            hash_dic[chr(i)] = 0

        for s in astr:
            hash_dic[s] += 1

        # 这里还有优化空间，这样写方便些
        if max(hash_dic.values()) > 1:
            return False
        else:
            return True




if __name__ == '__main__':
    astr = "leetcode"
    a = Solution()
    print(a.isUnique(astr))