/*
 * https://leetcode-cn.com/problems/valid-parentheses/
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> q;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                q.push(s[i]);
            }
            else {
                if (q.empty() || (!check(q.top(), s[i])))
                    return false;
                q.pop();
            }
        }
        if (!q.empty())
            return false;
        return true;
    }

    bool check(char x, char y) {
        if (x == '(' && y == ')')
            return true;
        if (x == '{' && y == '}')
            return true;
        if (x == '[' && y == ']')
            return true;
        return false;
    }
};

int main() {
    Solution solution;
    string s = "]";
    bool flag = solution.isValid(s);
    cout << flag << endl;

}
