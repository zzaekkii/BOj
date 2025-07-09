// 9290번 틱택토 이기기 - 실버4 / 구현 
#include <bits/stdc++.h>
using namespace std;

int T;
string board[4];
char namgyu;

void printBoard(){
	for(int i=0;i<3;i++,cout << '\n')
		cout << board[i];
}

void findMove(){
	// 행. 
	for(int i=0;i<3;i++){
		int cnt=0, jaewoo=0;
		for(int j=0;j<3;j++){
			if(board[i][j]==namgyu)cnt++;
			else if(board[i][j]!='-')jaewoo++;
		}
		if(cnt==2&&!jaewoo){
			for(int j=0;j<3;j++)board[i][j]=namgyu;
			printBoard();
			return;
		}
	}
	
	// 열.
	for(int i=0;i<3;i++){
		int cnt=0, jaewoo=0;
		for(int j=0;j<3;j++){
			if(board[j][i]==namgyu)cnt++;
			else if(board[j][i]!='-')jaewoo++;
		}
		if(cnt==2&&!jaewoo){
			for(int j=0;j<3;j++)board[j][i]=namgyu;
			printBoard();
			return;
		}
	}
	
	// 우측 대각선. 
	for(int i=0;i<1;i++){
		int cnt=0, jaewoo=0;
		for(int j=0;j<3;j++){
			if(board[j][j]==namgyu)cnt++;
			else if(board[j][j]!='-')jaewoo++;
		}
		if(cnt==2&&!jaewoo){
			for(int j=0;j<3;j++)board[j][j]=namgyu;
			printBoard();
			return;
		}
	}
	
	// 좌측 대각선.
	for(int i=0;i<1;i++){
		int cnt=0, jaewoo=0;
		for(int j=0;j<3;j++){
			if(board[j][2-j]==namgyu)cnt++;
			else if(board[j][2-j]!='-')jaewoo++;
		}
		if(cnt==2&&!jaewoo){
			for(int j=0;j<3;j++)board[j][2-j]=namgyu;
			printBoard();
			return;
		}
	}
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    
    for(int tst=1;tst<=T;tst++){
    	// 입력. 
    	for(int i=0;i<3;i++)
    		cin >> board[i];
    	
    	cin >> namgyu;
    	
    	cout << "Case " << tst << ":\n";
		findMove();
	}
}
