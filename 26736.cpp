#include <bits/stdc++.h>
using namespace std;

string S;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> S;

    cout << count(S.begin(),S.end(),'A') << " : " << count(S.begin(),S.end(),'B');
}
