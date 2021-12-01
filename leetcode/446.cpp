#include <bits/stdc++.h>

using namespace std;

int main() {
    int a = 1;
    int &b = a;
    cout << b << endl;
    int d =  2;
    b = d;
    cout << b << endl;
    b = 3;
    cout << b << ' ' << d <<  ' ' << a << endl;
}
