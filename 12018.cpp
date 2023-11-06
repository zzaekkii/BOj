#include <bits/stdc++.h>
using namespace std;
int N, M, P, L;
int arr[100];
int pos[100];
int ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
    	memset(arr,0,100);
    	cin >> P >> L;
    	for(int j=0;j<P;j++)
    		cin >> arr[j];
    	sort(arr,arr+P);
    	if(L>P)pos[i]=1;
    	else pos[i]=arr[P-L];
	}
	sort(pos,pos+N);
	
	for(int i=0;i<N;i++){
		M-=pos[i];
		if(M<0)break;
		ans++;
	}
	cout << ans;
}
