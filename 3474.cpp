#include <bits/stdc++.h>
using namespace std;

int T,N;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;

    while(T--) {
        cin >> N;
        int ans=0,tmp=5;
        while(tmp<=N){
            ans+=N/tmp;
            tmp*=5;
        }
        cout << ans << '\n';
    }
}
