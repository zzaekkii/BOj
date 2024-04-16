#include <bits/stdc++.h>
using namespace std;

struct Elec{
	int n,v;
};

int N,T;
Elec Arr[100001];
int lis[100001];
int rec[100001];
int ans[100001];

bool cmp(Elec x,Elec y){
	return x.n<y.n;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=0;i<N;i++)
    	cin >> Arr[i].n >> Arr[i].v;
    
    sort(Arr,Arr+N,cmp);
        
    lis[0]=Arr[0].v;
    int idx=1,cnt=0;
    
    for(;idx<N;idx++){
    	if(Arr[idx].v>lis[cnt]){
    		lis[++cnt]=Arr[idx].v;
    		rec[idx]=cnt;
    	}
    	else{
    		int st=0,en=cnt;
    		while(st<en){
    			int md=(st+en)/2;
    			if(lis[md]<Arr[idx].v)
    				st=md+1;
    			else
    				en=md;
			}
			lis[en]=Arr[idx].v;
			rec[idx]=en;
		}
	}
	
	int mx=cnt;
	for(int i=N-1;i>=0;i--)
		if(mx==rec[i])ans[mx--]=Arr[i].n;
		
	cout << N-(++cnt) << '\n';
	
	mx=0;
	for(int i=0;i<N;i++){
		if(Arr[i].n==ans[mx]){
			mx++;
			continue;
		}
		cout << Arr[i].n << '\n';
	}	
}
