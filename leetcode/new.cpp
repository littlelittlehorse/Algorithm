#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long dp[100003];
    int mod = 1e9 + 7;
    int numDecodings(string s) {
        dp[0] = 1;
        dp[1] = (s[0] == '*' ? 9 : 1);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != '*') {
                if (s[i] != '0') dp[i + 1] = dp[i];
                if (s[i - 1] == '1') dp[i + 1] += dp[i - 1];
                else if (s[i - 1] == '2' && s[i] < '7') dp[i + 1] += dp[i - 1];
                else if(s[i - 1] == '*') {
                    if (s[i] < '7') dp[i + 1] += (dp[i - 1] * 2);
                    else dp[i + 1] += dp[i - 1];
                }
            } else {
                dp[i + 1] = dp[i] * 9;
                if (s[i - 1] == '1')
                    dp[i + 1] += dp[i - 1] * 9;
                else if(s[i - 1] == '2')
                    dp[i + 1] += dp[i - 1] * 6;
                else if(s[i - 1] == '*')
                    dp[i + 1] += dp[i - 1] * 15;
            }
            dp[i] %= mod;
        }
        return dp[s.size() - 1];
    }
};


int main() {

}