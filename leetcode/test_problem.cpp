#include <bits/stdc++.h>

using namespace std;


const int maxn = 2e5 + 7;

int n, a[maxn];
vector<int> no_one;
long long sum[maxn];


int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] != 1) {
            no_one.push_back(i);
        }
        sum[i] = sum[i - 1] + a[i];
    }
    sum[n + 1] = sum[n];
    no_one.push_back(n + 1);

    int ans = n;
    int cur_one_num = 0;
    for (int i = 1; i <= n; i++) {
        long long tsum;
        long long mul = a[i];
        if (a[i] != 1) {
            cur_one_num++;
            if (cur_one_num == no_one.size() - 1)
                break;
        }
        int pos = no_one[cur_one_num];
        int tmp_one_num = cur_one_num;
        while(pos < no_one[no_one.size() - 1]) {
            mul = mul * a[pos];
            tsum = sum[pos] - sum[i - 1];

            if (mul == tsum) {
                ans++;
//                cout << i << ' ' << pos << endl;
                tmp_one_num++;
                pos = no_one[tmp_one_num];

            } else if(mul > tsum) {
                if (sum[no_one[tmp_one_num + 1] - 1] - sum[no_one[tmp_one_num]] >= mul - tsum) {
//                    cout << i << ' ' << no_one[tmp_one_num + 1] << endl;

                    ans++;
                }
                tmp_one_num++;
                pos = no_one[tmp_one_num];
            } else {

                tmp_one_num++;
                pos = no_one[tmp_one_num];
            }

        }
    }
    cout << ans << endl;

}
