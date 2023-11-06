#include <bits/stdc++.h>
using namespace std;
int N, M, P, L;

int arr[100][100];
int pos[100];
int ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
    	cin >> P >> L;
    	for(int j=0;j<P;j++)
    		cin >> arr[i][j];
    	sort(arr,arr+P);
    	if(L>P)pos[i]=1;
    	else pos[i]=arr[P-1-L];
	}
	sort(pos,pos+N);
	for(int i=0;i<N&&L>0;i++){
		
	}
		
}
