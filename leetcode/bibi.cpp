#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 7;

int n, k, a[maxn], sum[maxn];


int main() {
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    int ans = k * sum[n];
    sort(sum + 1, sum + n);
    for (int i = 1; i < k; i++) {
        ans -= sum[i];
    }
    printf("%d\n", ans);
    return 0;
}

