#include <bits/stdc++.h>
using namespace std;
int N,K;
int arr[31][31];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    
    for(int i=1;i<=N;i++){
    	for(int j=1;j<=i;j++){
    		if(j==1||j==i)arr[i][j]=1;
    		else{
    			arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
			}
    		if(i==N&&j==K){
    			cout << arr[i][j];
    			return 0;
			}
		}
	}
}
