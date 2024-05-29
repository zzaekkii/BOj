#include <bits/stdc++.h>
using namespace std;

int L,C;
char B;
string S;
string make;
int od,ev;

void Dfs(int idx){
	if(make.length()==L&&od>0&&ev>1){
		cout << make << '\n';
		return;
	}
	for(int i=idx;i<C;i++){
		if(make[make.length()-1]<S[i]){
			if(S[i]=='a'||S[i]=='e'||S[i]=='i'||S[i]=='o'||S[i]=='u')od++;
			else ev++;
			make+=S[i];
			
			Dfs(idx+1);
			
			if(S[i]=='a'||S[i]=='e'||S[i]=='i'||S[i]=='o'||S[i]=='u')od--;
			else ev--;
			make.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> L >> C;
	
	for(int i=0;i<C;i++){
		cin >> B;
		S+=B;
	}
	sort(S.begin(),S.end());
	
	for(int i=0;i<C;i++){
		if(S[i]=='a'||S[i]=='e'||S[i]=='i'||S[i]=='o'||S[i]=='u')od++;
		else ev++;
		make+=S[i];
		
		Dfs(1);
		
		if(S[i]=='a'||S[i]=='e'||S[i]=='i'||S[i]=='o'||S[i]=='u')od--;
		else ev--;
		make.pop_back();
	}
}
