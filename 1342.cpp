#include <bits/stdc++.h>
using namespace std;

string S;
int alph[26];
int l,cnt;

void dfs(int st,string tmp){
	if(st==l){
		bool f=1;
		for(int i=1;i<l;i++)
			if(tmp[i]==tmp[i-1]){
				f=0;
				break;
			}
		if(f)cnt++;
	}
	
	for(int i=0;i<26;i++)
		if(alph[i]){
			tmp+=97+i;
			alph[i]--;
			
			dfs(st+1,tmp);
			tmp.erase(tmp.size()-1);
			alph[i]++;
		}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> S;
	l=S.length();
	
	for(int i=0;S[i];i++)
		alph[S[i]-97]++;
	
	dfs(0,"");
	
	cout << cnt;
}
