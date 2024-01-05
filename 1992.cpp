#include <bits/stdc++.h>
using namespace std;
int N;
string S;
bool board[65][65];

void qt(int x,int y,int s){
	if(s==1){
		cout << board[x][y];
		return;
	}
	bool f=1;
	
	for(int i=x;i<x+s;i++){
		for(int j=y;j<y+s;j++)
			if(board[i][j]!=board[x][y]){
				f=0;
				break;
			}
		if(!f)break;
	}
	
	if(f){
		cout << board[x][y];
		return;
	}
	
	cout << '(';
	qt(x,y,s/2);
	qt(x,y+s/2,s/2);
	qt(x+s/2,y,s/2);
	qt(x+s/2,y+s/2,s/2);
	cout << ')';
} 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=0;i<N;i++){
    	cin >> S;
    	for(int j=0;j<N;j++)
    		board[i][j]=S[j]-48;
    }
    
    qt(0,0,N);
}
