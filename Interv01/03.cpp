//
// Created by Air on 2023/2/26.
//
// https://leetcode.cn/problems/string-to-url-lcci/

#include "iostream"

using namespace std;

class Solution {
public:
    string replaceSpaces(string S, int length) {
        string res("");
        for (int i = 0; i < length; ++i)
            if (S[i] != ' ')
                res += S[i];
            else
                res += "%20";
        return res;
    }
};

int main() {
    Solution test;
    string S("hello world");
    cout << test.replaceSpaces(S, 8) << endl;
    return 0;
}