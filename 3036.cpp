#include <bits/stdc++.h>
using namespace std;

int gcd_n, N, arr[100];

int GCD(int a, int b){ // 유클리드 호제법 
	if (b == 0) return a;
	return GCD(b, a % b);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    using namespace std;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 1; i < N; i++){
		gcd_n = GCD(arr[0], arr[i]); // 최대공약수
		cout << arr[0] / gcd_n << "/" << arr[i] / gcd_n << "\n";
	}
}
