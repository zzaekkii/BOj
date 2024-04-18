#include <bits/stdc++.h>
using namespace std;

int T,N,M,A,B;
vector<pair<int,int>> book;
int own[1010];
bool check[1010];

bool dfs(int s){
	int l=book[s].second-book[s].first+1;
	for(int i=0;i<l;i++){
		int gift=book[s].first+i;
		if(check[gift])continue;
		check[gift]=1;
		
		if(!own[gift]||dfs(own[gift])){
			own[gift]=s;
			return 1;
		}
	}	
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	
	while(T--){
		cin >> N >> M;
		
		book.clear();
		book.push_back({0,0});
		
		for(int i=1;i<=M;i++){
			cin >> A >> B;
			book.push_back({A,B});
		}
		
		int ans=0;
		fill(own,own+1010,0);
		for(int i=1;i<=M;i++){
			fill(check,check+1010,0);
			if(dfs(i))ans++;
		}
		cout << ans << '\n';
	}
}
