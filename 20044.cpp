#include <bits/stdc++.h>
using namespace std;

int N, ans=0x7FFFFFFF;
int W[200000];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=0;i<2*N;i++) cin >> W[i];
    sort(W,W+2*N);
    
    for(int i=0;i<N;i++)
        if(W[i]+W[2*N-i-1]<ans)ans=W[i]+W[2*N-i-1];
    
    cout << ans;
}
