#include <bits/stdc++.h>
using namespace std;

int F, S, G, U, D;
int dis[1000001];
queue<int> Q;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int i, j;
    cin >> F >> S >> G >> U >> D;
    
    fill(dis, dis+1000001, -1);
    
	dis[S]=0;
    Q.push(S);

    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int mv:{cur-D,cur+U}){
        	if(mv<=0||mv>F)continue;
        	if(dis[mv]!=-1)continue;
        	dis[mv]=dis[cur]+1;
        	Q.push(mv);
		}
    }
    if(dis[G]==-1) cout << "use the stairs";
    else cout << dis[G];
}
