#include <bits/stdc++.h>
using namespace std;

int N;
int Arr[100001];
int lis[100001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=0;i<N;i++)
    	cin >> Arr[i];
    	
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
	cout << N-(cnt+1);
}
