
//
//  matrix_reader.cpp
//  LeetCode
//
//  Created by Max on 2018/10/14.
//  Copyright © 2018 Max. All rights reserved.
//

#include <vector>
#include <iostream>

using namespace std;

int matrix_reader() {
    // Solution solution;
    
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
    
    //ans = solution.updateMatrix(ans);
    
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
