#include <bits/stdc++.h>
using namespace std;

int N, R, C;

int cntZ(int n, int r, int c){ // r행(y축) c열(x축) 
	if(!n) return 0;
	int qt = 1 << (n-1); // 한 쿼터 내 개수.
	
	if(r<qt&&c<qt) return cntZ(n-1,r,c); // 1번째 면.
	if(r<qt&&c>=qt) return qt*qt + cntZ(n-1,r,c-qt); // 2번째 면. 
	if(r>=qt&&c<qt) return 2*qt*qt + cntZ(n-1,r-qt,c); // 3번째 면.
	else return 3*qt*qt + cntZ(n-1,r-qt,c-qt); // 4번째 면.
}

int main(){	
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N >> R >> C;
	
	cout << cntZ(N,R,C);	
}
