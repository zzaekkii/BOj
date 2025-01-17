// 16165번 걸그룹 마스터 준석이 - 실버3 / #해시맵 
#include <bits/stdc++.h>
using namespace std;

map<string,vector<string>> mp;
map<string,string> srch;
int N, M, T;
string group, person, S;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	
	while(N--){
		cin >> group >> T;
		
		while(T--){
			cin >> person;
			mp[group].emplace_back(person);
			srch[person]=group;
		}
		
		sort(mp[group].begin(),mp[group].end());
	}
	
	while(M--){
		cin >> S >> T;
		
		if(T){
			cout << srch[S] << '\n';
		}
		else{
			for(auto a: mp[S])
				cout << a << '\n';
		}
	}
}
