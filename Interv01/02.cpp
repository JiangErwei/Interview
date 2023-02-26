//
// Created by Air on 2023/2/26.
//
// https://leetcode.cn/problems/check-permutation-lcci/

#include "iostream"
#include "unordered_map"
#include "string"
using namespace std;

class Solution {
public:
    // 哈希策略
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;

        unordered_map<char, int> HashMap;
        int i;

        for (i = 0; i < s1.size(); i++)
            HashMap[s1[i]]++;

        for (i = 0; i < s2.size(); i++)
            HashMap[s2[i]]--;

        bool flag(true);
        for (auto iter = HashMap.begin(); iter !=HashMap.end() ; ++iter)
            if (iter->second) {
                flag = false;
                break;
            }
        return flag;
    }
};

int main() {
    Solution test;
    string s1("abcd");
    string s2("bcda");
    cout << test.CheckPermutation(s1, s2) << endl;
    return 0;
}