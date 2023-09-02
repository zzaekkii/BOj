#include <bits/stdc++.h>
using namespace std;

int N;

bool col[30], l_diag[30], r_diag[30]; // 열, 좌대각, 우대각. 
int cnt;

void func(int n){
	if(n==N){
		cnt++;
		return;
	}
	for(int i=0;i<N;i++){
		if(col[i]||l_diag[i+n]||r_diag[i-n+N-1])continue;
		col[i]=l_diag[i+n]=r_diag[i-n+N-1]=1;
		func(n+1);
		col[i]=l_diag[i+n]=r_diag[i-n+N-1]=0;
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    func(0);
    cout << cnt;
}
