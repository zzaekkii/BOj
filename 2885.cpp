#include <bits/stdc++.h>
using namespace std;

int K;
int cnt;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> K;
	
	int n=1;
	while(n<K)n*=2;
	cout << n << ' ';
	
	while(K>0)
		if(K>=n)K-=n;
		else n/=2,cnt++;
	
	cout << cnt;
}
