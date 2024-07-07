#include <bits/stdc++.h>
using namespace std;

int N,H,V;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> H >> V;
    H=max(N-H,H);
    V=max(N-V,V);
    cout << H*V*4;
}
