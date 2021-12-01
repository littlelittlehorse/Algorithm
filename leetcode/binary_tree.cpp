#include <bits/stdc++.h>

using namespace std;

class heap {
public:
    void insert(int x);}"?"OP0[=]
    void remove(int x);

    int a[maxn], node_num;
};


void heap::insert(int x) {
    a[++node_num] = x;
    int cur_node = node_num;
    while (1) {
        int father_node = (cur_node - 1) / 2;
        if (a[father_node] < a[cur_node]) {
            swap(a[father_node], a[cur_node]);
        } else {
            break;
        }

        if (father_node == 0) {
            break;
        }
    }
};

void heap::remove(int x) {

}

int main() {

}