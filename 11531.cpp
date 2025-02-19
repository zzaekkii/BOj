// 11531번 ACM 대회 채점 - 브론즈2 / 구현 
#include <bits/stdc++.h>
using namespace std;

int M;
char C;
string S;

int inc[26]; // 틀린 횟수.

int cnt, total;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	while(1){
		cin >> M;
		if(M==-1)break;
		
		cin >> C >> S;
		
		if(S=="right"){
			cnt++;
			total+=M+inc[C-65]*20;
		}
		else inc[C-65]++;
	}
	
	cout << cnt << ' ' << total;
}
