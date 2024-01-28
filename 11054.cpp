#include <bits/stdc++.h>
using namespace std;

int Arr[1001];
int lis[1001];
int N;

int LIS_L(int M){
    lis[0]=Arr[0];
    int idx=1,len=0;

    for(;idx<=M;idx++){
        if(lis[len]<Arr[idx])
            lis[++len]=Arr[idx];
        else{
            int l=0,r=len;
            while(l<r){
                int m=(l+r)/2;
                if(lis[m]<Arr[idx])
                    l=m+1;
                else
                    r=m;
            }
            lis[r]=Arr[idx];
        }
    }
    
	return len+1;
}

int LIS_R(int M){    
    lis[0]=Arr[N-1];
    int idx=N-1,len=0;

    for(;idx>=M;idx--){
        if(lis[len]<Arr[idx])
            lis[++len]=Arr[idx];
        else{
            int l=0,r=len;
            while(l<r){
                int m=(l+r)/2;
                if(lis[m]<Arr[idx])
                    l=m+1;
                else
                    r=m;
            }
            lis[r]=Arr[idx];
        }
    }
	    
	return len+1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=0;i<N;i++)
		cin >> Arr[i];
	
	int mx=0;
	
	for(int i=0;i<N;i++){
		int lis_l=LIS_L(i);
		int lis_r=LIS_R(i);
		mx=max(mx,lis_l+lis_r-1);
	}
	
	cout << mx;
}
