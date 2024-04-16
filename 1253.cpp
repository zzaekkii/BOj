#include <bits/stdc++.h>
using namespace std;

int N;
int A[2000];
int ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=0;i<N;i++)
    	cin >> A[i];
    	
    sort(A,A+N);
    
    for(int i=0;i<N;i++){
    	int l=0,r=N-1;
    	while(l<r){
    		if(A[l]+A[r]==A[i]){
    			if(l!=i&&r!=i){
    				ans++;
    				break;
				}
				else if(l==i)l++;
				else if(r==i)r--;
			}
			else if(A[l]+A[r]<A[i])l++;
			else r--;
		}
	}
	
	cout << ans;
}
