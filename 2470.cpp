#include <bits/stdc++.h>
using namespace std;

int N;
int Arr[100001];
int ans[3];
int mx=2'000'000'001;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=0;i<N;i++)
    	cin >> Arr[i];
    	
    sort(Arr,Arr+N);
    
    int l=0,r=N-1;
    while(l<r){
    	if(abs(Arr[l]+Arr[r])<mx){
    		mx=abs(Arr[l]+Arr[r]);
    		ans[0]=Arr[l],ans[1]=Arr[r];
		}
		if(Arr[l]+Arr[r]<0)l++; 
		else r--;
	}
    
	for(int i=0;i<2;i++)
	cout << ans[i] << ' ';
}
