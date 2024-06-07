#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int V,E,A,B,C;
vector<pair<int,pair<int,int>>> vec;
int parent[10001];
int ans=0;

int Find(int n){
	if(parent[n]==n)return n;
	else return parent[n]=Find(parent[n]);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> V >> E;
	
	for(int i=0;i<E;i++){
		cin >> A >> B >> C;
		vec.push_back({C,{A,B}});
	}
	sort(vec.begin(),vec.end());
	
	for(int i=1;i<=V;i++)parent[i]=i;
	
	for(int i=0;i<E;i++)
		if(Find(vec[i].Y.X)!=Find(vec[i].Y.Y)){
			parent[Find(vec[i].Y.Y)]=Find(vec[i].Y.X);
			ans+=vec[i].X;
		}
	
	cout << ans;
}
