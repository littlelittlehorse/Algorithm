#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

bool vis[30];

int pos[100004][5];
int presum[100004][5];

unordered_map<char, int> mp;

void init() {
    mp['U'] = 0;
    mp['B'] = 1;
    mp['R'] = 2;
    mp['Y'] = 3;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            pos[i][j] = presum[i][j] = 0;
        }
    }

}

void trans(int x, char c) {
    if (c == 'U') {
        pos[x][mp['U']] = 1;
    } else if (c == 'B') {
        pos[x][mp[c]] = 1;

    } else if (c == 'R') {
        pos[x][mp[c]] = 1;

    } else if (c == 'Y') {
        pos[x][mp[c]] = 1;

    } else if (c == 'O') {
        pos[x][mp['R']] = 1;
        pos[x][mp['Y']] = 1;

    } else if (c == 'P') {
        pos[x][mp['R']] = 1;
        pos[x][mp['B']] = 1;

    } else if (c == 'G') {
        pos[x][mp['Y']] = 1;
        pos[x][mp['B']] = 1;

    } else if (c == 'A') {
        pos[x][mp['R']] = 1;
        pos[x][mp['B']] = 1;
        pos[x][mp['Y']] = 1;
    }
}

bool check(int l, int r, int k) {
    if (l == 0) {
//        cout << l << ' ' << r << ' ' << k << ' ' << presum[r][k] << endl;
        if (presum[r][k] == r - l + 1)
            return true;
        return false;
    }
//    cout << l << ' ' << r << ' ' << k << ' ' << presum[r][k] - presum[l - 1][k] << endl;
    if (presum[r][k] - presum[l - 1][k] == r - l + 1)
        return true;
    return false;

}

int main() {
    scanf("%d", &t);
    int cas = 0;
    while (t--) {
        scanf("%d", &n);
        init();

        cin >> s;

        for (int i = 0; i < s.size(); i++) {
            trans(i, s[i]);
        }

        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < 4; j++) {
                if (i == 0) {
                    presum[i][j] = pos[0][j];
                } else {
                    presum[i][j] = presum[i - 1][j] + pos[i][j];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 1; j < 4; j++) {
                int l = i, r = s.size() - 1;
                if (pos[i][j]) {
                    while (l < r) {
                        int mid = (l + r + 1) / 2;
                        if (check(l, mid, j)) {
                            l = mid;
                        } else {
                            r = mid - 1;
                        }
                    }

                    for (int k = i; k <= r; k++) {
                        pos[k][j] = 0;
                    }
                    ++ans;
                    // cout << i << ' ' << j << ' ' << l << ' ' << r << endl;
                }

            }
        }
        printf("Case #%d: %d\n", ++cas, ans);
    }
}
