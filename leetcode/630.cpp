#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int duration_time = 0;
        sort(courses.begin(), courses.end(), [](const auto &x, const auto &y){
            return x[1] < y[1];
        });

        priority_queue<int> q;

        for (int i = 0; i < courses.size(); i++) {
            duration_time += courses[i][0];
            q.push(courses[i][0]);
            while (duration_time > courses[i][1]) {
                int duration = q.top();
                q.pop();
                duration_time -= duration;
            }
        }
        return q.size();
    }
};