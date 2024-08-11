#include <bits/stdc++.h>
using namespace std;

int N,C;
int Item[31];

long long ans;
int leftem[32770],rightem[32770];
long long ldx,rdx,idx;

void Dfs(int *arr,int st,int en,int v){
	if(v>C)return;
	if(st==en){
		arr[idx++]=v;
		return;
	}
	
	Dfs(arr,st+1,en,v+Item[st]);
	Dfs(arr,st+1,en,v);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> C;
	
	for(int i=0;i<N;i++)
		cin >> Item[i];
	
	Dfs(leftem,0,N/2,0); ldx=idx; idx=0;
	Dfs(rightem,N/2,N,0); rdx=idx;
	
	sort(rightem,rightem+rdx);
	
	for(int i=0;i<ldx;i++){
		int l=0,r=rdx;
		while(l<r){
			int m=(l+r)/2;
			if(rightem[m]<=C-leftem[i])l=m+1;
			else r=m;
		}
 		ans+=l;
 	}
	
	cout << ans;
}
