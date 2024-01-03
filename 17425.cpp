#include <bits/stdc++.h>
using namespace std;
int T,N;
long long arr[1000001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
	for(int i=1;i<=1000000;i++)
		for(int j=i;j<=1000000;j+=i)
			arr[j]+=i;
    
    for(int i=1;i<=1000000;i++)
    	arr[i]+=arr[i-1];
    
    cin >> T;
    
    while(T--){
    	cin >> N;
    	cout << arr[N] << '\n';
	}
}
