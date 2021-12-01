#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string Digits[10] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    string Teens[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string Tens[10] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string Thousands[10] = {"", "Thousand", "Million", "Billion"};

    string numberToWords(int num) {
        if (num == 0)
            return "Zero";

        string ans;

        int unit = 1e9;
        for (int i = 3; i >= 0; i--) {
            int curNum = num / unit;
            if (curNum != 0) {
                num -= curNum * unit;
                string str;
                dfs(str, curNum);
                ans = ans + str + Thousands[i] + " ";
            }
            unit /= 1000;
        }

        while (ans.back() == ' ')
            ans.pop_back();
        return ans;
    }

    void dfs(string &s, int curNum) {
        if (curNum == 0)
            return;
        if (curNum < 10) {
            s = s + Digits[curNum] + " ";
        } else if (curNum < 20) {
            int curPos = curNum - 10;
            s = s + Teens[curPos] + " ";
        } else if (curNum < 100) {
            int curPos = curNum / 10;
            curNum -= curPos * 10;
            s = s + Tens[curPos] + " ";
            dfs(s, curNum);
        } else {
            int curPos = curNum / 100;
            s = s + Digits[curPos] + " Hundred ";
            dfs(s, curNum % 100);
        }

    }
};

int main() {
    string s[10] = {"a", "b"};
    cout << s[0] << ' ' << s[1] << endl;

}