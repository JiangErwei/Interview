# https://leetcode.cn/problems/compress-string-lcci/

class Solution:
    # 思路一：开辟新空间，存放"压缩后"的字符串，最后比较长度并返回
    def compressString_1(self, S: str) -> str:
        tmp = ""
        alf_comp = ""
        num_comp = []
        cnt = 0
        for s in S:
            if tmp != s and cnt != 0:
                num_comp.append(cnt)
                cnt = 0
            if tmp != s and cnt == 0:
                tmp = s
                alf_comp += tmp
            if tmp == s:
                cnt += 1
        num_comp.append(cnt)
        # return alf_comp, num_comp
        if len(S) <= len(alf_comp) + len(num_comp):
            return S
        else:
            # 可优化点
            # Python ： 不推荐使用字符串直接 res += s[i] 拼接，
            # 在 Python 中字符串是「不可变对象」，每次字符串拼接都会生成一个新字符串，效率低下。
            # 推荐使用列表，先将结果按照顺序添加，最终返回前拼接为字符串，因此只需要一次拼接操作。
            S_comp = ""
            for i in range(len(alf_comp)):
                S_comp += alf_comp[i]
                S_comp += str(num_comp[i])
            return S_comp

    # 优化思路：采用双指针法，另外在字符串拼接时采用列表一次拼接
    def compressString(self, S: str) -> str:
        if not S:
            return ""
        i, j, ls = 0, 0, len(S)
        list_S = []
        for j in range(ls):
            if S[j] != S[i]:
                list_S.append(str(j - i))
                i = j
            if i == j:
                list_S.append(S[i])
        list_S.append(str(j - i + 1))
        return ''.join(list_S) if len(list_S) < ls else S


if __name__ == '__main__':
    test = Solution()
    S = "rrrrrLLLLLPPPPPPRRRRRgggNNNNNVVVVVVVVVVDDDDDDDDDDIIIIIIIIIIlllllllAAAAqqqqqqqbbbNNNNffffff"
    S = "abbccd"
    print(test.compressString(S))

