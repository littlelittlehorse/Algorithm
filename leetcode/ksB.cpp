#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string)s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto& x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() {
    cerr << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int mod = 1e9 + 7;
vector<long long> A, B;
vector<vector<int>> V;
long long inv_1e6;

long long quick(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b % 2) res = res * a % mod;
        b /= 2;
        a = a * a % mod;
    }
    return res;
}

vector<vector<vector<long long>>> p_val;
vector<vector<long long>> P;
vector<vector<int>> fa;
vector<int> dep;
void dfs(int u, int pre, int d, long long p) {
    p_val[u][0][0] = B[u];
    p_val[u][0][1] = A[u];

    P[u][1] = p;
    P[u][0] = (1 - p) % mod;

    fa[u][0] = pre;
    dep[u] = d;
    for (auto it : V[u]) {
        dfs(it, u, d + 1, (p * A[it] % mod + (1 - p) % mod * B[it] % mod) % mod);
    }
}

int n, q;
void init() {
    for (int j = 1; j <= n; j++) {
        debug(j, p_val[j][0][0], p_val[j][0][1]);
    }

    for (int i = 1; i < 17; i++) {
        for (int j = 1; j <= n; j++) {
            int father = fa[j][i - 1];
            fa[j][i] = fa[father][i - 1];
            p_val[j][i][0] = (p_val[father][i - 1][0] * p_val[j][i - 1][1] % mod + (1 - p_val[father][i - 1][0]) % mod * p_val[j][i - 1][0] % mod) % mod;
            p_val[j][i][1] = (p_val[father][i - 1][1] * p_val[j][i - 1][1] % mod + (1 - p_val[father][i - 1][1]) % mod * p_val[j][i - 1][0] % mod) % mod;
            // debug(j, i, p_val[j][0][0], p_val[j][0][1]);
        }
    }
}

long long query(int x, int y) {
    long long res0 = 0, res1 = 1;
    if (dep[x] > dep[y]) swap(x, y);
    // debug(x, y);
    for (int j = 16; j >= 0 && dep[x] != dep[y]; j--) {
        if (dep[y] - (1 << j) < dep[x]) continue;
        int father = fa[y][j];
        long long new_res0 = (p_val[y][j][0] * res1 % mod + (1 - p_val[y][j][0]) % mod * res0 % mod) % mod;
        long long new_res1 = (p_val[y][j][1] * res1 % mod + (1 - p_val[y][j][1]) % mod * res0 % mod) % mod;
        res0 = new_res0;
        res1 = new_res1;
        y = fa[y][j];
    }
    if (x == y) {
        // 只有发生的概率
        res1 = P[x][1] * res1 % mod;
        res1 = (res1 + mod) % mod;
        return res1;
    }
    long long res2 = 0, res3 = 1;
    for (int j = 16; j >= 0; j--) {
        if (dep[x] - (1 << j) < 0 || fa[x][j] == fa[y][j]) continue;
        long long new_res0 = (p_val[y][j][0] * res1) % mod + ((1 - p_val[y][j][0]) % mod * res0 % mod) % mod;
        long long new_res1 = (p_val[y][j][1] * res1) % mod + ((1 - p_val[y][j][1]) % mod * res0 % mod) % mod;
        res0 = new_res0;
        res1 = new_res1;

        long long new_res2 = (p_val[x][j][0] * res3) % mod + ((1 - p_val[x][j][0]) % mod * res2 % mod) % mod;
        long long new_res3 = (p_val[x][j][1] * res3) % mod + ((1 - p_val[x][j][1]) % mod * res2 % mod) % mod;
        res2 = new_res2;
        res3 = new_res3;
        x = fa[x][j],
                y = fa[y][j];
    }

    long long new_res0 = (p_val[y][0][0] * res1) % mod + ((1 - p_val[y][0][0]) % mod * res0 % mod) % mod;
    long long new_res1 = (p_val[y][0][1] * res1) % mod + ((1 - p_val[y][0][1]) % mod * res0 % mod) % mod;

    long long new_res2 = (p_val[x][0][0] * res3) % mod + ((1 - p_val[x][0][0]) % mod * res2 % mod) % mod;
    long long new_res3 = (p_val[x][0][1] * res3) % mod + ((1 - p_val[x][0][1]) % mod * res2 % mod) % mod;
    res0 = new_res0;
    res1 = new_res1;
    res2 = new_res2;
    res3 = new_res3;
    int father = fa[x][0];
    long long res = (P[father][1] * res1 % mod * res3 % mod + P[father][0] * res0 % mod * res2 % mod) % mod;
    res %= mod;
    res = (res + mod) % mod;
    return res;
}

int main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    inv_1e6 = quick(1e6, mod - 2);
    debug(inv_1e6);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        A.clear();
        B.clear();
        V.clear();
        p_val.clear();
        P.clear();
        fa.clear();
        dep.clear();
        cin >> n >> q;

        A.resize(n + 1);
        B.resize(n + 1);
        V.resize(n + 1);
        p_val.resize(n + 1, vector<vector<long long>>(17, vector<long long>(2)));
        P.resize(n + 1, vector<long long>(2));
        fa.resize(n + 1, vector<int>(17));
        dep.resize(n + 1);

        long long p1;
        cin >> p1;
        p1 = p1 * inv_1e6 % mod;
        A[1] = p1, B[1] = p1;
        A[0] = 1, B[0] = 0;
        P[0][1] = 1, P[0][0] = 0;
        for (int i = 2; i <= n; i++) {
            int father;
            long long a, b;
            cin >> father >> a >> b;
            a = a * inv_1e6 % mod;
            b = b * inv_1e6 % mod;
            A[i] = a;
            B[i] = b;
            V[father].push_back(i);
        }
        dfs(1, 0, 0, p1);

        for (int i = 1; i <= n; i++) {
            debug(i, P[i]);
        }

        init();
        cout << "Case #" << t << ":";
        while (q--) {
            int u, v;
            cin >> u >> v;
            long long res = query(u, v);
            cout << " " << res;
        }
        cout << '\n';
    }
    return 0;
}