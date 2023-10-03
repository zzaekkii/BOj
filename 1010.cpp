#include <bits/stdc++.h>
using namespace std;

int T, N, M;
long long c[30][30];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	for(int i=1;i<30;i++){
		c[i][i]=1;
		c[i][1]=i;
	}    
	for(int i=2;i<30;i++)
		for(int j=2;j<30;j++)
			if(i>j) c[i][j]=c[i-1][j-1]+c[i-1][j];
    
	cin >> T;

	while(T--){
		cin >> N >> M;
		cout << c[M][N] << '\n';
	}
}
