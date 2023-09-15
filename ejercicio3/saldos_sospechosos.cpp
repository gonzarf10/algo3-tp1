//
// Created by gonza on 11/9/2023.
//

#include <iostream>
#include <vector>
#include <set>
#include <map>

void
traverse(int i, int &sum, std::vector<int> &entries, std::vector<std::set<int>> &reachable,
         std::vector<std::set<int>> &visited,
         std::vector<bool> &pos, std::vector<bool> &neg) {

    if (0 == i) {
        if (sum > 0) pos[0] = true;
        else neg[0] = true;
        return;
    }
    sum -= entries[i];
    if (reachable[i - 1].count(sum) > 0) {
        pos[i] = true;
        if (0 == visited[i - 1].count(sum)) {
            visited[i - 1].insert(sum);
            traverse(i - 1, sum, entries, reachable, visited, pos, neg);
        }
    }
    sum += 2 * entries[i];
    if (reachable[i - 1].count(sum) > 0) {
        neg[i] = true;
        if (0 == visited[i - 1].count(sum)) {
            visited[i - 1].insert(sum);
            traverse(i - 1, sum, entries, reachable, visited, pos, neg);
        }
    }
    sum -= entries[i];
}


std::string saldos_sospechosos(int n, int sum, std::vector<int> entries100) {
    std::string res = "";
    std::vector<int> entries;
    std::vector<std::set<int>> reachable;
    std::vector<std::set<int>> visited;
    std::vector<bool> pos, neg;

    int cases = 1;

    for (int i = 0; i < cases; i++) {

        sum /= 100;
        entries.clear();
        reachable.clear();
        visited = std::vector<std::set<int>>(n, std::set<int>());
        int x;
        x = entries100[0];
        x /= 100;
        entries.push_back(x);
        reachable.push_back({x, -x});
        for (int i = 0; i < n - 2; i++) {
            std::set<int> nextLevel;
            x = entries100[i+1];
            x /= 100;
            entries.push_back(x);
            for (int reachableSum: reachable[i]) {
                nextLevel.insert(reachableSum + x);
                nextLevel.insert(reachableSum - x);
            }
            reachable.push_back(nextLevel);
        }
        if (n > 1) {
            x = entries100[n - 1];
            entries.push_back(x / 100);
        }
        pos = std::vector<bool>(n, false);
        neg = std::vector<bool>(n, false);
        traverse(n - 1, sum, entries, reachable, visited, pos, neg);

        for (int i = 0; i < n; i++) {
            res += (pos[i] ? (neg[i] ? '?' : '+') : '-');
        }
    }

    return res;
}