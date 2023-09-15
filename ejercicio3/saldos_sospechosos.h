//
// Created by gonza on 11/9/2023.
//

#ifndef TP1_SALDOS_SOSPECHOSOS_H
#define TP1_SALDOS_SOSPECHOSOS_H

void
traverse(int i, int &sum, std::vector<int> &entries, std::vector<std::set<int>> &reachable,
         std::vector<std::set<int>> &visited,
         std::vector<bool> &pos, std::vector<bool> &neg);

std::string saldos_sospechosos(int n, int sum, std::vector<int> entries100);

#endif //TP1_SALDOS_SOSPECHOSOS_H
