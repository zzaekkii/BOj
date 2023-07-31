#include <bits/stdc++.h>
using namespace std;

int A1, A0, C, N;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> A1 >> A0 >> C >> N;
    
    if (A1*N+A0<=C*N&&A1<=C) cout << 1;
    else cout << 0;
}
