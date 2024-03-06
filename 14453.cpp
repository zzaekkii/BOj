#include <bits/stdc++.h>
using namespace std;

int arr[100001][3];
int N;
char C;

int ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=1;i<=N;i++){
    	cin >> C;
		
		for(int j=0;j<3;j++)arr[i][j]=arr[i-1][j];
		
		if(C=='H')arr[i][0]++;
		else if(C=='P')arr[i][1]++;
		else arr[i][2]++;
    }
    
    for(int i=1;i<=N;i++)
    	for(int j=0;j<3;j++)
    		ans=max(ans,arr[i][j]+max(arr[N][(j+1)%3]-arr[i][(j+1)%3],arr[N][(j+2)%3]-arr[i][(j+2)%3]));
    		
    cout << ans;    
}
