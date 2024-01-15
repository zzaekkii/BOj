#include <bits/stdc++.h>
using namespace std;

int N,X;
int idx;
long long one[21];
long long price;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=0;i<N;i++){
		cin >> X;
		idx=0;
		while(X>0){
			one[idx++]+=X%2;
			X/=2;
		}
	}
	
	for(int i=0;i<20;i++)
		price+=(1<<i)*one[i]*(N-one[i]);
		
	cout << price;
}
