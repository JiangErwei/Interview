# https://leetcode.cn/problems/zero-matrix-lcci/
from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows, cols = len(matrix), len(matrix[0])
        # 收集0元素坐标
        zeros = []
        for i in range(rows):
            for j in range(cols):
                if matrix[i][j] == 0:
                    zeros.append((i, j))

        zeros[::] = list(zip(*zeros))
        if zeros:
            for i in zeros[0]:
                for j in range(cols):
                    matrix[i][j] = 0

            for j in zeros[1]:
                for i in range(rows):
                    matrix[i][j] = 0


if __name__ == '__main__':
    test = Solution()
    matrix = [
        [0, 1, 2, 0],
        [3, 4, 5, 2],
        [1, 3, 1, 5]
    ]
    matrix = [[1]]
    test.setZeroes(matrix)
    print(matrix)
