#include <bits/stdc++.h>
using namespace std;

int N, K, a;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    a=60+K;
    if(N<=a) cout << N*1500;
    else cout << a*1500+(N-a)*3000;
}
