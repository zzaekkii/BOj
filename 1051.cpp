#include <bits/stdc++.h>
using namespace std;

int N,M;
string b[51];
int ans=1;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    for(int i=0;i<N;i++)
		cin >> b[i];
	
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++){
			int mx=min(N-1-i,M-1-j);
			char cur=b[i][j];
			for(int k=mx;k>0;k--)
				if(cur==b[i+k][j]&&cur==b[i][j+k]&&cur==b[i+k][j+k])
					ans=max(ans,(k+1)*(k+1));
		}
	
	cout << ans;
}
