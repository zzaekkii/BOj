// 2024 APC Extra A번 - #해시셋 
#include <bits/stdc++.h>
using namespace std;

int N;
string S;
unordered_set<string> us; 

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=0;i<N;i++){
		cin >> S;
		us.insert(S);
	}
	
	for(int i=0;i<N-1;i++){
		cin >> S;
		
		us.erase(us.find(S));
	}
	
	for(auto a: us)
		cout << a;
}
