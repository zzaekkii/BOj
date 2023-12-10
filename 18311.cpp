#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int N, K, T;
ll arr[100001];
ll sum;
int ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    
    for(int i=1;i<=N;i++){
    	cin >> T;
    	arr[i]+=arr[i-1]+T;
    	if(arr[i]>K){
			ans=i;
			break;
		}
	}
	
	if(!ans){
		sum=arr[N];
		for(int i=N;i>0;i--){
			sum+=arr[i]-arr[i-1];
			if(sum>K){
				ans=i;
				break;
			}
		}
	}
	cout << ans;
}
