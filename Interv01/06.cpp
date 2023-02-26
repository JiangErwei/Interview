//
// Created by Air on 2023/2/26.
//
// https://leetcode.cn/problems/compress-string-lcci/

#include "iostream"
using namespace std;

class Solution {
public:
    string compressString(string S) {
        if (S == "")
            return "";
        int i(0), j(0), ls(S.size());
        string res("");
        for (j = 0; j < ls; ++j) {
            if (S[i] != S[j]) {
                res += to_string(j - i);
                i = j;
            }
            if (i == j)
                res += S[i];
        }
        res += to_string(j - i);
        if (res.size() >= S.size())
            return S;
        else
            return res;
    }
};

int main() {
    Solution test;
    string S("abbccd");
    cout << test.compressString(S) << endl;
    return 0;
}