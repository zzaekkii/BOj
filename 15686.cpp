#include <bits/stdc++.h>
using namespace std;

struct Point{
	int x,y;
};

int N,M,T;
Point home[101],chicken[14];
int pick[14];
int hdx,cdx;

int ans=0x7FFFFFFF;

void dfs(int cnt,int idx){
	if(cnt==M){
		int sum=0;
		for(int i=0;i<hdx;i++){
			int mn=0x7FFFFFFF;
			for(int j=0;j<M;j++)
				mn=min(mn,abs(home[i].x-chicken[pick[j]].x)+abs(home[i].y-chicken[pick[j]].y));
			sum+=mn;
		}
		ans=min(ans,sum);
		return;
	}
	
	for(int i=idx;i<cdx;i++){
		pick[cnt]=i;
		dfs(cnt+1,i+1);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			cin >> T;
			if(T==1)home[hdx++]={i,j};
			else if(T==2)chicken[cdx++]={i,j};
		}
	
	dfs(0,0);
	
	cout << ans;
}
