//
// Created by Air on 2023/2/26.
//
// https://leetcode.cn/problems/one-away-lcci/

#include "iostream"
using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        if (abs(int(first.size() - second.size())) > 1)
            return false;
        if (first == second)
            return true;

        if (first.size() < second.size())
            std::swap(first, second);

        int first_p(0), second_p(0);
        int first_q(first.size()-1), second_q(second.size()-1);

        while (first_p < first_q && first[first_p] == second[second_p] ) {
            ++first_p;
            ++second_p;
        }
        while (first_p < first_q && first[first_q] == second[second_q]) {
            --first_q;
            --second_q;
        }

        return first_p == first_q;

    }
};

int main() {
    Solution test;
    string s1("bcd");
    string s2("abcd");
    cout << test.oneEditAway(s1, s2) << endl;
    return 0;
}