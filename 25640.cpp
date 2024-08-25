#include <bits/stdc++.h>
using namespace std;

string S,M;
int N;
int cnt;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> S >> N;
    
	while(N--){
		cin >> M;
		if(M==S)cnt++;
	}
    
	cout << cnt;
}
