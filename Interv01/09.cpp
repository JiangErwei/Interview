//
// Created by Air on 2023/2/27.
//
// https://leetcode.cn/problems/string-rotation-lcci/

#include "iostream"
#include "string"
using namespace std;

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        s2 += s2;
        return s2.find(s1) != s2.npos;
    }
};

int main() {
    string s1 = "aa", s2 = "aba";
    Solution test;
    cout << test.isFlipedString(s1, s2);
    return 0;
}