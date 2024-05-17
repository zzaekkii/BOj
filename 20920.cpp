#include <bits/stdc++.h>
using namespace std;

int N,M;
string S;
map<string,int> mp;

bool cmp(pair<string,int>& a,pair<string,int>&b){
	if(a.second==b.second)
		if(a.first.length()==b.first.length())
			return a.first<b.first;
		else return a.first.length()>b.first.length();
	else return a.second>b.second;
}

int main(){                      
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	
	for(int i=0;i<N;i++){
		cin >> S;
		if(S.length()>=M){
			if(mp.find(S)!=mp.end())mp[S]++;
			else mp.insert({S,1});
		}
	}
	
	vector<pair<string,int>> v(mp.begin(),mp.end());
	sort(v.begin(),v.end(),cmp);
	
	for(auto a:v)
		cout << a.first << '\n';
}
