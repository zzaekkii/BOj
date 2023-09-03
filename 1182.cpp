#include <bits/stdc++.h>
using namespace std;

int N, S;
int A[20];
int cnt;

void func(int num, int sum){
	if(num==N){
		if(sum==S)cnt++;
		return;
	}
	func(num+1,sum);
	func(num+1,sum+A[num]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> S;
    for(int i=0;i<N;i++) cin >> A[i];
    func(0,0);
    if(!S)cnt--;
    cout << cnt;
}
