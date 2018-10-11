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
#include <iostream>

using namespace std;

class Solution {
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

int matrix_01() {
    Solution solution;
    vector<vector<int>> ans;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> tmp;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            tmp.push_back(x);
        }
        ans.push_back(tmp);
    }
    
    ans = solution.updateMatrix(ans);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
