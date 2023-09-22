#include <bits/stdc++.h>
using namespace std;

int N, U, V;
vector<int> adj[100001];
int p[100001];

void dfs(int cur){
    for(int nxt: adj[cur]){
        if(p[cur]==nxt)continue;
        p[nxt]=cur;
        dfs(nxt);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i=0;i<N-1;i++){
        cin >> U >> V;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }
    dfs(1);
    for(int i=2;i<=N;i++)
        cout << p[i] << '\n';
}
