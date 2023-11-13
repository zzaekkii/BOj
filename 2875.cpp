#include <bits/stdc++.h>
using namespace std;
int N, M, K;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    while(K--)
        if(N/2<M)M--;
        else N--;
    cout << min(N/2,M);    
}
