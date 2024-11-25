// 4158번 CD - #해시맵 or #이분탐색 
#include <bits/stdc++.h>
using namespace std;

int N, M; // 상근이 N개, 선영이 M개.
int T; // CD 넘버. 
unordered_map<int,bool> m;
int cnt;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(1){
    	cin >> N >> M;
    	if(!N&&!M)break;
    	
    	m.clear();
    	cnt=0;
    	
    	for(int i=0;i<N;i++){
    		cin >> T;
    		m[T]=1;
		}
		
		for(int i=0;i<M;i++){
			cin >> T;
			if(m[T])cnt++;
		}
		
		cout << cnt << '\n';
	}
}
