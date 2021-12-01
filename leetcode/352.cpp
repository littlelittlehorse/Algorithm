#include <bits/stdc++.h>

using namespace std;
class SummaryRanges {
public:
    map<int, int> interval;
    SummaryRanges() {}
    void addNum(int val) {
        auto up = interval.upper_bound(val);
        auto down = (up == interval.begin() ? interval.end() : prev(up));

        if (down != interval.end() && (val >= down->first && val <= down->second)) {

        } else if ((up != interval.end() && up->first - 1 == val) && (down != interval.end() && down->second + 1 == val)) {
            int l = down->first, r = up->second;
            interval.erase(down->first);
            interval.erase(up->first);
            interval.emplace(l, r);
        } else if (down != interval.end() && down->second + 1 == val) {
            int l = down->first, r = val;
            interval.erase(l);
            interval.emplace(l, r);
        } else if (up != interval.end() && up->first - 1 == val) {
            int l = val, r = up->second;
            interval.erase(up->first);
            interval.emplace(l, r);
        } else {
            interval.emplace(val, val);
        }
        cout << interval.size() << endl;

    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (auto& it : interval) {
            ans.push_back({it.first, it.second});
        }
        return ans;
    }
};

int main() {
    map<int, int> intervals;
    intervals[1] = 1;
    intervals[2] = 2;
    auto it = intervals.lower_bound(1);
    it++;
    cout << it->first << ' ' << it->second << endl;
}