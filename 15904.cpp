#include <bits/stdc++.h>
using namespace std;

string S;
char x[5]="UCPC";
int cnt=0;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	getline(cin,S);
	
	for(int i=0;S[i];i++){
		if(cnt==4)break;
		if(S[i]==x[cnt])cnt++;
	}
	
	if(cnt==4)cout << "I love UCPC";
	else cout << "I hate UCPC";
}
