#include <bits/stdc++.h>

using namespace std;

pair<long long, pair<int, int> > segSum;

unordered_map<long long, pair<int, int> > mp;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &k);

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            sum[i] = sum[i - 1] + a[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                long long cur = sum[i] - sum[j - 1];

            }
        }

    }
}