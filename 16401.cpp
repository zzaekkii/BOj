#include <bits/stdc++.h>
using namespace std;
int M,N;
int Arr[1'000'001];

bool cmp(int a,int b){
	return a<b;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> M >> N;
    
    for(int i=0;i<N;i++)
    	cin >> Arr[i];
    	
    sort(Arr,Arr+N,cmp);
    
    int st=1,en=Arr[N-1];
    while(st<=en){
    	int cnt=0;
    	int md=(st+en)/2;
    	for(int i=0;i<N;i++)cnt+=Arr[i]/md;
    	if(cnt<M)en=md-1;
    	else st=md+1;
	}
	cout << en;
}
