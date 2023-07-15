/*
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N;
string S;
int dx[4]={-1,0,1,0}, dy[4]={0,-1,0,1};

queue<pair<int,int>> Q;

char board[101][101];
bool vis[101][101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int i, j;
    cin >> N;
    
    for(i=0;i<N;i++)
    	for(j=0;j<N;j++){
    		cin >> board[i][j];
    		if(board[i][j]=='R')
    	}
    
    Q.
    
    while(!Q.empty()){
    	
	}
}
*/
#include <bits/stdc++.h>
using namespace std;
int T, N;
string S1, S2;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    
    while(T--){
		map<string,int> M;
    	int i, cnt=1;
    	cin >> N;
    	
    	for(i=0;i<N;i++){
	    	cin >> S1 >> S2;
	    	M[S2]++;
		}
		
		for(auto a=M.begin();a!=M.end();a++){
			cnt*=(a->second)+1; // 안 입는 경우 추가.
		}		
		cout << cnt-1 << "\n"; // 알몸 빼기. 
	}
}
