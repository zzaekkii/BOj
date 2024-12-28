// 11648번 지속 - 브론즈3 / #수학 
#include <bits/stdc++.h>
using namespace std;

int N;
int ans;

void Conti(int n){
	if(n<10)return;
	
	ans++;
	
	int tmp=1;
	while(n){
		tmp*=n%10;
		n/=10;
	}
	
	Conti(tmp);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	Conti(N);
	
	cout << ans;
}
