#include <bits/stdc++.h>
using namespace std;
int N;
double arr[10001];
double ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    
    for(int i=1;i<=N;i++)
    	cin >> arr[i];
	
	ans=arr[1];
	
	for(int i=2;i<=N;i++){
		if(arr[i]*arr[i-1]>=arr[i])
			arr[i]*=arr[i-1];
		ans=max(ans,arr[i]);
	}
    
    cout << fixed;
	cout.precision(3);
	cout << ans;
}
