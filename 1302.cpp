#include <bits/stdc++.h>
using namespace std;

int N;
string S;
map<string,int> M;
string ans;
int mx;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	while(N--){
		cin >> S;
		M[S]++;
	}
	
	for(auto a:M)
		if(a.second>mx){
			mx=a.second;
			ans=a.first;
		}
	
	cout << ans;
}
