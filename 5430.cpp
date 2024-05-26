#include <bits/stdc++.h>
using namespace std;

int T,N,X;
char tmp;
string P;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	
	while(T--){		
		cin >> P >> N >> tmp; // '['
		if(!N)cin >> tmp; // ']'
		
		deque<int> Q;
		
		for(int i=0;i<N;i++){
			cin >> X >> tmp;
			Q.push_back(X);
		}
		
		bool f=1,z=1;
		for(int i=0;P[i];i++){
			if(P[i]=='R'){
				z^=1;
			}
			else if(P[i]=='D'){
				if(Q.empty()){
					cout << "error\n";
					f=0;
					break;
				}
				if(z)Q.pop_front();
				else Q.pop_back();
			}
		}
		if(f){
			cout << '[';
			int l=Q.size();
			for(int i=0;i<l-1;i++){
				if(z){
					cout << Q.front() << ',';
					Q.pop_front();
				}
				else{
					cout << Q.back() << ',';
					Q.pop_back();
				}
			}
			if(l){
				if(z)cout << Q.front(),Q.pop_front();
				else cout << Q.back(),Q.pop_back();
			}
			cout << "]\n";
		}
	}
}
