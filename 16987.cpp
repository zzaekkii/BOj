#include <bits/stdc++.h>
using namespace std;

struct Egg{
	int s,w;
};

Egg E[9];

int N;
int ans;

void Dfs(int hand){		
	if(hand==N){
		int cnt=0;
		for(int i=0;i<N;i++)
			if(E[i].s<=0)cnt++;
	
		ans=max(ans,cnt);
		return;
	}	
	
	if(E[hand].s<=0){
		Dfs(hand+1);
		return;
	}
	
	bool hit=0;
	for(int i=0;i<N;i++)
		if(i!=hand&&E[i].s>0){
			hit=1;
			E[hand].s-=E[i].w;
			E[i].s-=E[hand].w;
			Dfs(hand+1);
			E[hand].s+=E[i].w;
			E[i].s+=E[hand].w;
		}
	
	if(!hit)Dfs(hand+1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=0;i<N;i++)
		cin >> E[i].s >> E[i].w;
	
	Dfs(0);
	
	cout << ans;
}
