#include <bits/stdc++.h>
using namespace std;

int T,N,M,X;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	
	while(T--){
		cin >> N;
		map<int,bool> MP;
		for(int i=0;i<N;i++){
			cin >> X;
			MP[X]=1;
		}
				
		cin >> M;
		while(M--){
			cin >> X;
			bool ex=0;
			if(MP[X])ex=1;
			
			cout << ex << '\n';
		}
	}
}
