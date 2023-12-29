#include <bits/stdc++.h>
using namespace std;
int R,C,W;
int arr[31][31];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C >> W;
    
    for(int i=1;i<=30;i++){
    	for(int j=1;j<=i;j++){
    		if(j==1||j==i)arr[i][j]=1;
    		else{
    			arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
			}
		}
	}
	
	int ans=0;
	for(int i=0;i<W;i++)
		for(int j=0;j<=i;j++)
			ans+=arr[R+i][C+j];
	cout << ans;
}
