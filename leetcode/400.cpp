#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findNthDigit(int n) {
        long long left = 1, right = (1LL << 31) - 1, mid;
        while (left < right) {
            mid = (left + right + 1) / 2;
            if (totalDigits(mid) <= n)
                left = mid;
            else
                right = mid - 1;
        }

        if (totalDigits(left) == n)
            return left % 10;
        else
            return getKthPos(left + 1, n - totalDigits(left));
    }

    long long totalDigits(long long x) {
        long long x_length = 0, tmp_x = x;
        while (tmp_x) {
            x_length++;
            tmp_x /= 10;
        }

        long long length_sum = 0, length = 1, cur_num = 9;
        while (length < x_length) {
            length_sum += cur_num * length;
            length++;
            cur_num *= 10;
        }

        int num = 1;
        for (int i = 2; i <= length; i++)
            num *= 10;
        length_sum += (x - num + 1) * length;
        return length_sum;
    }

    int getKthPos(int x, int k) {
        stack<int> st;
        while (x) {
            st.push(x % 10);
            x /= 10;
        }
        int p = 0, ans = -1;
        while (p < k) {
            ans = st.top();
            st.pop();
            ++p;
        }
        return ans;
    }
};