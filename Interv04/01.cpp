//
// Created by Air on 2023/3/2.
//
// https://leetcode.cn/problems/route-between-nodes-lcci/

#include "vector"
#include "unordered_map"
#include "unordered_set"
#include "queue"
#include "iostream"
using namespace std;


class Solution {
private:
    // 邻接表形式存储有向图
    unordered_map<int, unordered_set<int>> graph_map;
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        // 建立表头
        for (int i = 0; i < n; ++i)
            graph_map[i] = unordered_set<int>();
        // 根据有向边建立邻接表
        for (auto edge : graph)
            graph_map[edge[0]].insert(edge[1]);

        // BFS寻路
        queue<int> que;
        que.push(start);
        bool flag(false);
        unordered_map<int, int> visited; // 访问过的点将value设为1
        while (!que.empty()) {
            for (int item : graph_map[que.front()]) {
                if (item != target && visited[item] != 1) {
                    que.push(item);
                    visited[item]++;
                }
                else if (item == target){
                    flag = true;
                    break;
                }
            }
            que.pop();
        }
        return flag;
    }
};


int main() {
    int n(12);
    vector<vector<int>> graph = {{0, 1}, {1, 2}, {1, 3}, {1, 10}, {1, 11}, {1, 4}, {2, 4}, {2, 6}, {2, 9}, {2, 10}, {2, 4}, {2, 5}, {2, 10}, {3, 7}, {3, 7}, {4, 5}, {4, 11}, {4, 11}, {4, 10}, {5, 7}, {5, 10}, {6, 8}, {7, 11}, {8, 10}};
    int start(2), target(3);
    Solution test;
    cout << test.findWhetherExistsPath(n, graph, start, target);
    return 0;
}