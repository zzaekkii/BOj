#include <bits/stdc++.h>
using namespace std;

int N;
int Arr[51];
int p,sum;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;

	for(int i=1;i<=N;i++)
		cin >> Arr[i];
	Arr[0]=-9999;
	
	sort(Arr,Arr+N+1);
	
	for(int i=1;i<=N;i++)
		if(Arr[i]<=0)p=i;
	
	for(int i=2;i<=p-p%2;i+=2)
		sum+=Arr[i]*Arr[i-1];
	if(p%2)sum+=Arr[p];
	
	for(int i=N;i>p+(N-p)%2;i-=2)
		if(Arr[i-1]==1)sum+=Arr[i]+Arr[i-1];
		else sum+=Arr[i]*Arr[i-1];
	
	if((N-p)%2)sum+=Arr[p+(N-p)%2];
	
	cout << sum;
}
