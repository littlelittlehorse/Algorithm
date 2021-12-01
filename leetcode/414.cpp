#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int> &nums) {
        set<int> q;
        for (int i = 0; i < nums.size(); i++) {
            q.insert(nums[i]);
            if (q.size() > 3) {
                q.erase(q.begin());
            }
        }
        if (q.size() == 3)
            return *q.begin();
        return *q.rbegin();
    }
};

class Solution {
public:
    const long long Min = -(1LL << 31);
    int thirdMax(vector<int> &nums) {
        long fi = Min, se = Min, th = Min;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > fi) {
                th = se;
                se = fi;
                fi = nums[i];
            } else if (fi > nums[i] &&  nums[i] > se) {
                th = se;
                se = nums[i];
            } else if (se > nums[i] && nums[i] > th) {
                th = nums[i];
            }
        }

        if (th == Min)
            return fi;
        return th;
    }
};

int main() {
    set<int> q;
    q.insert(1);
    q.insert(12);
    cout << (*q.begin()) << endl;
}