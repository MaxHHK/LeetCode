//
//  _542_01-matrix.cpp
//  LeetCode
//
//  Created by Max on 2018/10/11.
//  Copyright © 2018 Max. All rights reserved.
//

#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <iostream>

using namespace std;

class Solution2 {
    vector<vector<int>> ans;
    int n;
    void update(int i0, int j0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int tmp = ans[i][j];
                if (tmp != 0) {
                    int dis = abs(i0 - i) + abs(j0 - j);
                    if (tmp == -1 || tmp > dis) {
                        ans[i][j] = dis;
                    }
                }
                
            }
        }
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        ans = matrix;
        n = static_cast<int>(matrix.size());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (ans[i][j]) {
                    ans[i][j] = -1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!ans[i][j]) {
                    update(i, j);
                }
            }
        }
        return ans;
    }
};

struct myPoint{
    int x, y, l;
    myPoint(int x, int y, int level = 0): x(x), y(y), l(level) {}
};

class Solution {
    const int step[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
    int row, col;
    void bfsUpdate(vector<vector<int>>& ans) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (ans[i][j]) {
                    int level, max = curMax(i, j, ans);
                    if (max == 1) {
                        ans[i][j] = 1;
                    } else {
                        level = bfs(i, j, max, ans);
                        if (level == -1) {
                            ans[i][j] = max;
                        } else {
                            ans[i][j] = level < max ? level : max;
                        }
                    }
                }
            }
        }
    }
    int curMax(int i, int j, vector<vector<int>>& ans) {
        int max = INT_MAX - 1;
        for (int index = 2; index < 4; index++) {
            int nexti = i + step[index][0], nextj = j + step[index][1];
            if (nexti >= 0 && nexti < row && nextj >= 0 && nextj < col) {
                max = max < ans[nexti][nextj] ? max : ans[nexti][nextj];
            }
        }
        return max + 1;
    }
    int bfs(int i, int j, int maxLevel, vector<vector<int>>& ans) {
        queue<myPoint> Q;
        myPoint tmp(i, j, 1);
        Q.push(tmp);
        while (!Q.empty()) {
            tmp = Q.front();
            Q.pop();
            i = tmp.x;
            j = tmp.y;
            if (tmp.l >= maxLevel) {
                return maxLevel;
            }
            for (int index = 0; index < 2; index++) {
                int nexti = i + step[index][0], nextj = j + step[index][1];
                if (nexti >= 0 && nexti < row && nextj >= 0 && nextj < col) {
                    if (ans[nexti][nextj] == 0) {
                        return tmp.l;
                    } else {
                        Q.push(myPoint(nexti, nextj, tmp.l + 1));
                    }
                }
            }
        }
        return -1;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        row = static_cast<int>(matrix.size());
        if (row == 0) {
            return matrix;
        }
        col = static_cast<int>(matrix[0].size());
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j]) {
                    matrix[i][j] = -1;
                }
            }
        }
        bfsUpdate(matrix);
        return matrix;
    }
};

int matrix_01() {
    Solution solution;
    vector<vector<int>> ans;
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
        ans.push_back(tmp);
    }
    
    ans = solution.updateMatrix(ans);
    
    int row = int(ans.size());
    int col = int(ans[0].size());
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
