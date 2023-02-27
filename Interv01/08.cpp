//
// Created by Air on 2023/2/27.
//
// https://leetcode.cn/problems/zero-matrix-lcci/

#include "iostream"
#include "vector"
#include "unordered_set"
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows(matrix.size()), cols(matrix[0].size());
        // 收集0元素坐标
        unordered_set<int> zero_rows, zero_cols;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (!matrix[i][j]) {
                    zero_rows.insert(i);
                    zero_cols.insert(j);
                }

        if (zero_rows.size() && zero_cols.size()) {
            for (int i : zero_rows)
                for (int j = 0; j < cols; ++j)
                    matrix[i][j] = 0;
            for (int i : zero_cols)
                for (int j = 0; j < rows; ++j)
                    matrix[j][i] = 0;
        }

    }
};

int main() {
    vector<vector<int>> matrix = {
            {0,1,2,0},
            {3,4,5,2},
            {1,3,1,5}
    };
    Solution test;
    test.setZeroes(matrix);
    int rows(matrix.size()), cols(matrix[0].size());
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
