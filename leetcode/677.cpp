#include <bits/stdc++.h>

using namespace std;

class MapSum {
public:
    int trie[2507][30];
    int sum[2507];
    int root, idx;
    MapSum() {
        root = idx = 1;
    }

    void insert(string key, int val) {
        int cur = root;
        for (int i = 0; i < key.size(); i++) {
            int c = key[i] - 'a';
            if (!trie[cur][c]) trie[cur][c] = ++idx;
            cur = trie[cur][c];
            sum[cur] += val
        }
    }

    int sum(string prefix) {
        int cur = root;
        bool flag = true;
        for (int i = 0; i < prefix.size(); i++) {
            int c = prefix[i] - 'a';
            if (!trie[cur][c]) {
                flag = false;
                break;
            }
            cur = trie[cur][c];
        }
        return sum[cur];
    }
};
