#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N;
ll Arr[5001];
ll ans[3];
ll mx=3'000'000'001;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=0;i<N;i++)
    	cin >> Arr[i];
    	
    sort(Arr,Arr+N);
    
    for(int i=0;i<N-2;i++){
    	int l=i+1,r=N-1;
    	while(l<r){
    		if(abs(Arr[i]+Arr[l]+Arr[r])<mx){
    			mx=abs(Arr[i]+Arr[l]+Arr[r]);
    			ans[0]=Arr[i],ans[1]=Arr[l],ans[2]=Arr[r];
			}
			if(Arr[i]+Arr[l]+Arr[r]<0)l++; 
			else r--;
		}
	}
	
	for(int i=0;i<3;i++)
	cout << ans[i] << ' ';
}
