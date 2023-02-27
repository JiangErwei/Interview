//
// Created by Air on 2023/2/27.
//
// https://leetcode.cn/problems/rotate-matrix-lcci/
// 矩阵

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N(matrix.size());
        if (!N)
            return;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (i != j)
                    swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 采用指针的方式进行遍历，不需要用&
        //for (auto iter = matrix.begin(); iter != matrix.end(); ++iter) {
        //    reverse(iter->begin(), iter->end());
        //}

        // C++11的for遍历，实质上是copy，不改变原对象，需要加&
        for (auto& iter : matrix) {
            reverse(iter.begin(), iter.end());
        }
    }
};


int main() {
    vector<vector<int>> matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    Solution test;
    test.rotate(matrix);
    int N = matrix.size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
