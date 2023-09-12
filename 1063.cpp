#include <bits/stdc++.h>
using namespace std;

int N; // 이동 횟수 
string K, S, M; // 킹, 돌, 이동 정보 


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> K >> S >> N;
    
    int kx=K[0]-64, ky=K[1]-48;
    int sx=S[0]-64, sy=S[1]-48;
    
	while(N--){
		cin >> M;
		int mx=0, my=0;
		
		switch(M[0]){
			case 'R':
				mx=1;
				if(M[1]=='T')my=1;
				if(M[1]=='B')my=-1;
				break;
			case 'L':
				mx=-1;
				if(M[1]=='T')my=1;
				if(M[1]=='B')my=-1;
				break;
			case 'B':
				my=-1;
				break;
			case 'T':
				my=1;
				break;
		}
		
		int cur_kx=kx+mx, cur_ky=ky+my;
		int cur_sx=sx+mx, cur_sy=sy+my;
		
		if(cur_kx<1||cur_kx>8||cur_ky<1||cur_ky>8)continue;
		if(cur_kx==sx&&cur_ky==sy){
			if(cur_sx<1||cur_sx>8||cur_sy<1||cur_sy>8)continue;
			sx=cur_sx, sy=cur_sy;
		}
		kx=cur_kx, ky=cur_ky;
	}
	cout << (char)(kx+64) << ky << '\n';
	cout << (char)(sx+64) << sy;
}
