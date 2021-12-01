#include <stdio.h>
#include <string.h>
#include <iostream>
#include <unordered_map>

using namespace std;

const int maxn = 2e5 + 7;

int n;
char s[maxn];

int pre_dir[maxn][5], suf_dir[maxn][5];

unordered_map<int, int> mp[maxn];


int trans(char c) {
    if (c == 'U') return 1;
    else if (c == 'D') return 2;
    else if (c == 'L') return 3;
    else
        return 4;
}

void init() {
    for (int i = 0; i < maxn; i++) {
        mp[i].clear();
        for (int j = 0; j < 5; j++)
            pre_dir[i][j] = suf_dir[i][j] = 0;
    }
}


void solve() {
    init();
    scanf("%d", &n);
    scanf("%s", s + 1);

    for (int i = 1; i <= n; i++) {
        int d = trans(s[i]);
        pre_dir[i][d]++;
        for (int j = 1; j <= 4; j++) {
            pre_dir[i][j] += pre_dir[i - 1][j];
        }
    }

    for (int i = n; i > 0; i--) {
        int d = trans(s[i]);
        suf_dir[i][d]++;
        for(int j = 1; j < 5; j++) {
            suf_dir[i][j] += suf_dir[i + 1][j];
        }

    }

    for (int i = n; i > 0; i--) {
        int up = suf_dir[i][1] - suf_dir[i][2];
        int left = suf_dir[i][3] - suf_dir[i][4];
        mp[up+maxn][left]++;
    }

    int res_up = pre_dir[n][1] - pre_dir[n][2];
    int res_left = pre_dir[n][3] - pre_dir[n][4];


    long long ans = 0;
    for (int i = 1; i <= n; i++) {

        int up = pre_dir[i - 1][1] - pre_dir[i - 1][2];
        int left = pre_dir[i - 1][3] - pre_dir[i - 1][4];
        mp[up + maxn][left]--;
        ans += mp[maxn - up - res_up][-left - res_left];

    }
    printf("%lld\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        solve();
    }
}