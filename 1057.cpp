// 1057번 토너먼트 - 실버4 / #브루트포스 
#include <bits/stdc++.h>
using namespace std;

int N, J, H;
int roun; 

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> J >> H;
	
	while(J!=H){
		J=(J+1)/2;
		H=(H+1)/2;
		roun++;
	}
	
	cout << roun;
}
