//
//  _412_Fizz Buzz.cpp
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
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for (int i = 1; i <= n; i++) {
            if (i % 5 == 0 && i % 3 == 0) {
                result.push_back("FizzBuzz");
            } else if (i % 5 == 0) {
                result.push_back("Buzz");
            } else if (i % 3 == 0) {
                result.push_back("Fizz");
            } else {
                char ans[12];
                sprintf(ans, "%d", i);
                result.push_back(ans);
            }
        }
        return result;
    }
};

int FizzBuzz() {
    
    Solution solution;
    
    int n;
    cin >> n;
    vector<string> ans = solution.fizzBuzz(n);
    for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
        cout << *it << endl;
    }
    
    return 0;
}
