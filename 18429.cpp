#include <bits/stdc++.h>
using namespace std;

int N, K;
int gain[8];
int ans, w;
bool use[8];

void dfs(int ord){
    if(ord==N)ans++;
    else
        for(int i=0;i<N;i++)
            if(!use[i]){
                use[i]=1;
                if(w+gain[i]>=0){
                    w+=gain[i];
                    dfs(ord+1);
                    w-=gain[i];
                    use[i]=0;
                }
                else use[i]=0;
            }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> gain[i];
        gain[i]-=K;
    }
    dfs(0);
    cout << ans;
}
