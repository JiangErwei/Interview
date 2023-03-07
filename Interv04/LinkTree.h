//
// Created by Air on 2023/3/2.
//

#ifndef INTERVIEW_LINKTREE_H
#define INTERVIEW_LINKTREE_H

#include "iostream"
#include "vector"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


#endif //INTERVIEW_LINKTREE_H
