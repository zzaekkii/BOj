// 14670번 병약한 영정 - 실버4 / 해시맵 
#include <bits/stdc++.h>
using namespace std;

int N, R;
unordered_map<int, int> M;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	while(N--){
		int eff, medi;
		cin >> eff >> medi;
		M[eff]=medi;
	}
	
	cin >> R;
	
	while(R--){
		int cnt, sym;
		vector<int> V;
		
		cin >> cnt;
		
		for(int i=0;i<cnt;i++){
			cin >> sym;
			if(M.find(sym)!=M.end())V.emplace_back(M[sym]);
		}
		
		if(V.size()!=cnt) cout << "YOU DIED";
		else for(auto a: V) cout << a << ' ';
		cout << '\n';
	}
}
