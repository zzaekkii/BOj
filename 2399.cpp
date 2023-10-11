#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int X[10001];
ll ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=0;i<N;i++)
        cin >> X[i];
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            ans+=abs(X[i]-X[j]);
    
    cout << ans;
}
