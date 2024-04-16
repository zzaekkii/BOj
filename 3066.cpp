#include <bits/stdc++.h>
using namespace std;

int T,N;
int Arr[40001];
int lis[40001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    
    while(T--){
        cin >> N;
        for(int i=0;i<N;i++)
        	cin >> Arr[i];
        
        memset(lis,0,40001);
        lis[0]=Arr[0];
        int idx=1,cnt=0;
        
        for(;idx<N;idx++){
        	if(Arr[idx]>lis[cnt])
        		lis[++cnt]=Arr[idx];
        	else{
        		int st=0,en=cnt;
        		while(st<en){
        			int md=(st+en)/2;
        			if(lis[md]<Arr[idx])
        				st=md+1;
        			else
        				en=md;
	    		}
	    		lis[en]=Arr[idx];
	    	}
	    }
	    cout << cnt+1 << '\n';
    }
}
