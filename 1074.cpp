#include <bits/stdc++.h>
using namespace std;

int N, R, C;

int cntZ(int n, int r, int c){ // r��(y��) c��(x��) 
	if(!n) return 0;
	int qt = 1 << (n-1); // �� ���� �� ����.
	
	if(r<qt&&c<qt) return cntZ(n-1,r,c); // 1��° ��.
	if(r<qt&&c>=qt) return qt*qt + cntZ(n-1,r,c-qt); // 2��° ��. 
	if(r>=qt&&c<qt) return 2*qt*qt + cntZ(n-1,r-qt,c); // 3��° ��.
	else return 3*qt*qt + cntZ(n-1,r-qt,c-qt); // 4��° ��.
}

int main(){	
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N >> R >> C;
	
	cout << cntZ(N,R,C);	
}
