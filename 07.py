# https://leetcode.cn/problems/rotate-matrix-lcci/
import copy
from typing import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        matrix.reverse()
        # 需要注意列表赋值并没有改变内存空间中的存储内容
        # 此时可借助切片对列表进行重新赋值
        # 原理涉及到深浅拷贝
        matrix[::] = list(zip(*matrix))
        # matrix[::] = [list(row) for row in matrix]


if __name__ == '__main__':
    matrix = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]
    test = Solution()
    test.rotate(matrix)
    print(matrix)
