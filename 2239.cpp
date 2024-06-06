#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

short dx[]={-1,-1,-1,0,0,0,1,1,1},dy[]={-1,0,1,-1,0,1,-1,0,1};

string S;
short board[10][10];
pair<short,short> P[82];
short cnt;

void Dfs(short idx){
	if(idx==cnt){
		for(short i=0;i<9;i++){
			for(short j=0;j<9;j++)
				cout << board[i][j];
			cout << '\n';
		}
		exit(0);
	}
	
	auto cur=P[idx];
	short nx=cur.X/3*3+1;
	short ny=cur.Y/3*3+1;
	// 세로줄 없고, 가로줄 없고, 현재 3x3칸 없고.
	
	bool num[10]={0}; 
	short psb[10]={0};
	short pdx=0;
	for(short dir=0;dir<9;dir++) // 3x3.
		if(board[nx+dx[dir]][ny+dy[dir]])
			num[board[nx+dx[dir]][ny+dy[dir]]]=1;
	
	for(short i=1;i<=9;i++)
		if(!num[i])psb[pdx++]=i;
	
	for(short i=0;i<pdx;i++){ // 3x3칸에서 없는 숫자만. 
		bool ex=1;
		for(short j=0;j<9;j++) // 가로줄 , 세로줄. 
			if(board[cur.X][j]==psb[i]||board[j][cur.Y]==psb[i])
				ex=0;
		if(ex){
			board[cur.X][cur.Y]=psb[i];
			Dfs(idx+1);
			board[cur.X][cur.Y]=0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for(short i=0;i<9;i++){
		cin >> S;
		for(short j=0;j<9;j++){
			board[i][j]=S[j]-48;
			if(!board[i][j])
				P[cnt++]={i,j};
		}
	}
		
	Dfs(0);
}
