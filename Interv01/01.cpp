//
// Created by Air on 2023/2/23.
//
// https://leetcode.cn/problems/is-unique-lcci/?favorite=xb9lfcwi

#include "iostream"
#include "string"
#include "unordered_map"
#include "unordered_set"
using namespace std;

class Solution {
public:
    // 采用hash_set进行优化
    bool isUnique(string astr) {
        unordered_set<char> HashSet;
        bool flag(true);
        for (int i = 0; i < astr.size(); ++i) {
            if (HashSet.count(astr[i])) {
                flag = false;
                break;
            }
            else
                HashSet.insert(astr[i]);
        }
        return flag;
    }
    bool isUnique_1(string astr) {
        unordered_map<char, int> HashMap;
        for (int i = 0; i < astr.size(); ++i)
            HashMap[astr[i]]++;
        int max(0);
        for (auto iter(HashMap.begin()); iter != HashMap.end(); ++iter)
            if (max < iter->second)
                max = iter->second;
        if (max > 1)
            return false;
        else
            return true;
    }
};

int main(){
    Solution test;
    string astr("leetcode");
    cout << test.isUnique(astr);
    return 0;
}