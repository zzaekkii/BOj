#include <bits/stdc++.h>
using namespace std;

int N;
int A[100001],B[100001];
int tmp[100001];
int lis[100001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=0;i<N;i++)cin >> A[i];
    for(int i=0;i<N;i++)cin >> B[i];
    
    for(int i=0;i<N;i++)tmp[A[i]]=i;
    for(int i=0;i<N;i++)B[i]=tmp[B[i]];
    	
    lis[0]=B[0];
    int idx=1,cnt=0;
    
    for(;idx<N;idx++){
    	if(B[idx]>lis[cnt])
    		lis[++cnt]=B[idx];
    	else{
    		int st=0,en=cnt;
    		while(st<en){
    			int md=(st+en)/2;
    			if(lis[md]<B[idx])
    				st=md+1;
    			else
    				en=md;
			}
			lis[en]=B[idx];
		}
	}
	cout << cnt+1;
}
