// 16719번 ZOAC - 골드5 / #문자열 #DFS
#include <bits/stdc++.h>
using namespace std;

string S;
bool vis[101];
int l;

void Dfs(int st, int en){
	if(st==en)return;
	
	int pick=0;
	char tmp='Z'+1;
	
	for(int i=st;i<en;i++)
		if(S[i]<tmp){
			tmp=S[i];
			pick=i;
		}
		
	vis[pick]=1;
	
	for(int i=0;i<l;i++)
		if(vis[i])cout << S[i];
	cout << '\n';
	
	// 사전 순으로 출력되려면, 얘 오른쪽부터 조져야함. 
	Dfs(pick+1,en);
	// 끝나면 앞에 애들 보기. 
	Dfs(st,pick);
} 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> S;
    
    l=S.length();
    
    Dfs(0,l);
}
