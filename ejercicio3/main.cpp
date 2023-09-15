#include <iostream>
#include <vector>
#include <set>
#include <map>


int n, sum;
std::vector<int> entries;
std::vector<std::set<int>> reachable;
std::vector<std::set<int>> visited;
std::vector<bool> pos, neg;

void traverse(int i) {
    if (0 == i) {
        if (sum > 0) pos[0] = true;
        else neg[0] = true;
        return;
    }
    sum -= entries[i];
    if (reachable[i-1].count(sum) > 0) {
        pos[i] = true;
        if (0 == visited[i - 1].count(sum)) {
            visited[i - 1].insert(sum);
            traverse(i - 1);
        }
    }
    sum += 2 * entries[i];
    if (reachable[i - 1].count(sum) > 0) {
        neg[i] = true;
        if (0 == visited[i - 1].count(sum)) {
            visited[i - 1].insert(sum);
            traverse(i - 1);
        }
    }
    sum -= entries[i];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int cases;
    std::cin >> cases;
    for (int i = 0; i < cases; i++) {
        std::cin >> n >> sum;

        sum /= 100;
        entries.clear();
        reachable.clear();
        visited = std::vector<std::set<int>>(n, std::set<int>());
        int x;
        std::cin >> x;
        x /= 100;
        entries.push_back(x);
        reachable.push_back({x, -x});
        for (int i = 0; i < n-2; i++) {
            std::set<int> nextLevel;
            std::cin >> x;
            x /= 100;
            entries.push_back(x);
            for (int reachableSum : reachable[i]) {
                nextLevel.insert(reachableSum + x);
                nextLevel.insert(reachableSum - x);
            }
            reachable.push_back(nextLevel);
        }
        if (n > 1){
            std::cin >> x;
            entries.push_back(x / 100);
        }
        pos = std::vector<bool>(n, false);
        neg = std::vector<bool>(n, false);
        traverse(n - 1);
        for (int i = 0; i < n; i++) {
            std::cout << (pos[i] ? (neg[i] ? '?' : '+') : '-');
        }
        std::cout << '\n';
    }
}

