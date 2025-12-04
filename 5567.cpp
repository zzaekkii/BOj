#include <bits/stdc++.h>
using namespace std;

int N, M, A, B;
vector<int> f[501];

bool res[501];
int ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    while(M--){
        cin >> A >> B;
        f[A].emplace_back(B);
        f[B].emplace_back(A);
    }
    
    for(int a: f[1]){
        res[a]=1;
        
        for(int b: f[a])
            res[b]=1;
    }
    
    for(int i=2;i<=N;i++)
        if(res[i])ans++;
    
    cout << ans;
}
