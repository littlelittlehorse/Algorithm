#include <bits/stdc++.h>

using namespace std;


class TopVotedCandidate {
public:
    vector<int> times;
    vector<int> first_persons;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        vector<int> person_count(5001, 0);
        int cur_max = -1, max_person_id;
        for (int i = 0; i < persons.size(); i++) {
            if (++person_count[persons[i]] > cur_max) {
                max_person_id = persons[i];
                cur_max = person_count[persons[i]];
            }
            first_persons[i] = max_person_id;
        }
        this->times = times;
    }

    int q(int t) {
        int ans_pos = upper_bound(times.begin(), times.end()) - times.begin() - 1;
        return first_persons[ans_pos];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */