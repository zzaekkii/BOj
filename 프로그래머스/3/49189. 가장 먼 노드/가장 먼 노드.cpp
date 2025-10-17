#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<int> node[20001];
    
    int len=edge.size();
    for(int i=0;i<len;i++){
        int a=edge[i][0];
        int b=edge[i][1];
        
        node[a].emplace_back(b);
        node[b].emplace_back(a);
    }
    
    int dist[20001]={0};
    for(int i=1;i<=n;i++) dist[i]=-1;
    dist[1]=0;
        
    queue<int> Q;
    Q.push(1);
    
    int mx=0;
    while(!Q.empty()){
        int cur=Q.front(); Q.pop();
        
        for(int nxt: node[cur]){
            if(dist[nxt]==-1){
                dist[nxt]=dist[cur]+1;
                mx=max(dist[nxt],mx);
                Q.push(nxt);
            }
        }
    }
    
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(dist[i]==mx) cnt++;
    
    return cnt;
}