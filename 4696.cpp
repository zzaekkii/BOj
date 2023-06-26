#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    double N;
    while(1){
    	cin >> N;
    	if(N==0)break;
    	cout << fixed;
		cout.precision(2);
		cout << 1+N+pow(N,2)+pow(N,3)+pow(N,4) << "\n";
	}
}
