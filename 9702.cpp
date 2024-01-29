#include <bits/stdc++.h>
using namespace std;

int T,N;
int Arr[501];
int lis[501];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    
    for(int t=1;t<=T;t++){
    	cin >> N;
    	
	    for(int i=0;i<N;i++)
	        cin >> Arr[i];
	    
		int sum=0;
				
		for(int i=0;i<N;i++){
			lis[0]=Arr[i];
			int idx=i+1,ans=0;
			sum+=1;
			
			for(;idx<N;idx++){
				if(lis[ans]<Arr[idx])
				        lis[++ans]=Arr[idx];
				else{
				    int l=0,r=ans;
				    while(l<r){
				        int m=(l+r)/2;
				        if(lis[m]<Arr[idx])
				            l=m+1;
				        else
				            r=m;
				    }
				    lis[r]=Arr[idx];
				}
				sum+=ans+1;
			}
		}
		cout << "Case #" << t << ": " << sum << '\n';
	}
}
