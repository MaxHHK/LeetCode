//
//  main.cpp
//  LeetCode
//
//  Created by Max on 2018/10/10.
//  Copyright © 2018 Max. All rights reserved.
//

#include <string>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

class Solution {
    int n, *isVisited, *isMal, numOfMalInSub;
    vector<int> tmpSegment, malSegment;
    
    void DFS(int node, vector<vector<int>>& graph) {
        for (int i = 0; i < n; i++) {
            if (!isVisited[i] && graph[node][i] == 1) {
                isVisited[i] = 1;
                if (isMal[i]) {
                    numOfMalInSub++;
                    malSegment.push_back(i);
                }
                tmpSegment.push_back(i);
                DFS(i, graph);
            }
        }
    }
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        sort(initial.begin(), initial.end());
        int maxMinimize = 0, minIndex = initial[0];

        n = static_cast<int>(graph.size());
        isVisited = new int[n];
        isMal = new int[n];
        memset(isVisited, 0, sizeof(int) * n);
        memset(isMal, 0, sizeof(int) * n);
        
        for (vector<int>::iterator it = initial.begin(); it != initial.end(); it++) {
            isMal[*it] = 1;
        }
        
        for (int i = 0; i < n; i++) {
            if (!isVisited[i]) {
                tmpSegment.clear();
                malSegment.clear();
                numOfMalInSub = 0;
                isVisited[i] = 1;
                if (isMal[i]) {
                    numOfMalInSub++;
                    malSegment.push_back(i);
                }
                tmpSegment.push_back(i);
                DFS(i, graph);
                if (numOfMalInSub == 1 && static_cast<int>(tmpSegment.size()) > maxMinimize) {
                    maxMinimize = static_cast<int>(tmpSegment.size());
                    minIndex = malSegment[0];
                }
            }
        }
        
        delete [] isVisited;
        delete [] isMal;
        return minIndex;
    }
};

int main() {
    Solution solution;
    vector<int> init;
    vector<vector<int>> graph;
    char X, x;
    
    cin >> X;
    while (X != ']' ) {
        cin >> x;
        vector<int> tmp;
        while (x != ']') {
            cin >> x;
            if (x == '0' || x == '1') {
                tmp.push_back(x - '0');
            }
        }
        cin >> X;
        graph.push_back(tmp);
    }
    
    cin >> x;
    int num;
    while (x != ']') {
        cin >> num;
        init.push_back(num);
        cin >> x;
    }
    
    cout << solution.minMalwareSpread(graph, init);
    
    return 0;
}
