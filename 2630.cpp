#include <bits/stdc++.h>
using namespace std;

int N;
bool board[129][129];
int white, blue;

bool check(int n, int x, int y){ // 모두 같은 색인지 판별.
	for(int i=x;i<x+n;i++)
		for(int j=y;j<y+n;j++)
			if(board[i][j]!=board[x][y]) return 0;
	return 1;
}

void paper(int n, int x, int y){ // 증가 or 분할. 
	if(check(n,x,y)){
		if(!board[x][y])white++;
		else blue++;
		return;
	}
	
	for(int i=0;i<2;i++) // 4분할 / 각 사각형 시작 부분. 
		for(int j=0;j<2;j++)
			paper(n/2,x+n/2*i,y+n/2*j);
			// 변은 절반씩 감소, 최초 x y에서 살 붙이기. 
}

int main(){	
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N;
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> board[i][j];
	
	paper(N,0,0);
				
	cout << white << '\n' << blue;
}
