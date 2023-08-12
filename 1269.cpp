#include <bits/stdc++.h>
using namespace std;

map<int,bool> M;
int A, B;

int main(){	
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> A >> B;
	A+=B;
	while(A--){
		cin >> B;
		if(M[B])M.erase(B);
		else M[B]=1;
	}
	cout << M.size();
}

// 만약 맵을 안 쓰면?
/*
int A, B, N;
bool arr[100000001];
int ans;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int i, t;
	cin >> A >> B;
	
	while(A--){
		cin >> t;
		arr[t]=1;
		ans++;
	}
	
	while(B--){
		cin >> t;
		ans+=!arr[t]?1:-1;
	}		
	cout << ans;
}
*/
