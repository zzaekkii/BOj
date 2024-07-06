#include <bits/stdc++.h>
using namespace std;

int N;
int S[21][21];

bool join[21];
int ans=0x7FFFFFFF;

void Dfs(int idx,int cnt){
	if(cnt==N/2){
		int a=0,b=0;
		
		for(int i=0;i<N-1;i++)
			if(join[i]){
				for(int j=i+1;j<N;j++)
					if(join[j])a+=S[i][j]+S[j][i];
			}
			else{
				for(int j=i+1;j<N;j++)
					if(!join[j])b+=S[i][j]+S[j][i];
			}
		
		ans=min(ans,abs(a-b));
		
		return;
	}
	
	for(int i=idx;i<N;i++)
		if(!join[i]){
			join[i]=1;
			Dfs(i,cnt+1);
			join[i]=0;
		}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> S[i][j];
	
	Dfs(0,0);
	
	cout << ans;
}
