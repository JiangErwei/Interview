//
// Created by Air on 2023/2/26.
//
// https://leetcode.cn/problems/palindrome-permutation-lcci/

#include "iostream"
#include "unordered_map"
using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> HashMap;
        for (int i = 0; i < s.size(); ++i)
            HashMap[s[i]]++;

        int odds(0);
        for (auto c : HashMap)
            if (c.second % 2)
                ++odds;

        return odds < 2;
    }
};

int main() {
    Solution test;
    string S("tactcoa");
    cout << test.canPermutePalindrome(S) << endl;
    return 0;
}